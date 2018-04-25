package com.jongsuny.idea.gui;

import com.intellij.openapi.actionSystem.ActionGroup;
import com.intellij.openapi.actionSystem.ActionManager;
import com.intellij.openapi.components.ServiceManager;
import com.intellij.openapi.project.Project;
import com.intellij.openapi.wm.WindowManager;
import com.jongsuny.idea.component.TouchBarBuilder;
import com.jongsuny.idea.setting.TouchBarCustomizableActionGroupProvider;
import com.thizzer.jtouchbar.JTouchBar;
import com.thizzer.jtouchbar.item.TouchBarItem;
import jiconfont.icons.FontAwesome;
import jiconfont.swing.IconFontSwing;

import java.awt.*;
import java.beans.PropertyChangeListener;
import java.util.ArrayList;
import java.util.Collection;
import java.util.UUID;
import java.util.stream.Collectors;

public class TouchBar {

    protected JTouchBar jTouchBar;

    protected Project project;

    protected Collection<ItemListener> itemListeners;

    protected Frame touchBarFrame;

    public static TouchBar getInstance(Project project) {
        return ServiceManager.getService(project, TouchBar.class);
    }

    public TouchBar(Project project) {
        this(project, "");
    }

    public TouchBar(Project project, String identifier) {
        this.itemListeners = new ArrayList<>();
        this.project = project;
        this.touchBarFrame = WindowManager.getInstance().getFrame(this.project);
        IconFontSwing.register(FontAwesome.getIconFont());

        jTouchBar = createJTouchBar(identifier);
        jTouchBar.show(this.touchBarFrame);

        ActionManager.getInstance().addAnActionListener((action, dataContext, event) -> {
            Collection<ItemListener> listeners = itemListeners.stream()
                .filter(_itemListener -> _itemListener.getActionId()
                    .equals(ActionManager.getInstance().getId(action)))
                        .collect(Collectors.toList());

            listeners.forEach(itemListener -> {
                event.getPresentation().addPropertyChangeListener(
                    itemListener.getPropertyChangeListener()
                );
                itemListeners.remove(itemListener);
            });
        });
    }

    public void addItem(TouchBarItem touchBarItem) {
        this.jTouchBar.addItem(touchBarItem);
    }

    public void addItemListener(ItemListener listener) {
        this.itemListeners.add(listener);
    }

    public Project project() {
        return this.project;
    }

    public JTouchBar jTouchBar() {
        return this.jTouchBar;
    }

    public void refresh() {
        jTouchBar.setItems(null);
        ActionGroup touchBarGroup = TouchBarCustomizableActionGroupProvider.getTouchBarSchema();

        // Add all the buttons to the Touch bar.
        TouchBarBuilder.fromAction(touchBarGroup).apply(this);
    }

    public void show() {
        jTouchBar.show(this.touchBarFrame);
    }

    protected JTouchBar createJTouchBar(String identifier) {
        jTouchBar = new JTouchBar();
        jTouchBar.setCustomizationIdentifier("intellij-touch:"+identifier+":"+UUID.randomUUID().toString());
        return jTouchBar;
    }

    public void destroy() {
        jTouchBar.hide(this.touchBarFrame);
        String identifier = jTouchBar.getCustomizationIdentifier();
        jTouchBar = new JTouchBar();
        jTouchBar.setCustomizationIdentifier(identifier);
    }

    public interface ItemListener {
        String getActionId();
        PropertyChangeListener getPropertyChangeListener();
    }
}
