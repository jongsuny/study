package com.jongsuny.idea.component;

import com.intellij.openapi.actionSystem.ActionManager;
import com.intellij.openapi.actionSystem.AnAction;
import com.intellij.openapi.application.ApplicationManager;
import com.jongsuny.idea.gui.TouchBar;
import com.thizzer.jtouchbar.common.Color;
import com.thizzer.jtouchbar.common.Image;
import com.thizzer.jtouchbar.item.TouchBarItem;
import com.thizzer.jtouchbar.item.view.TouchBarButton;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.beans.PropertyChangeListener;
import java.io.ByteArrayOutputStream;
import java.io.IOException;

import static com.intellij.util.ui.UIUtil.createImage;

public class ButtonBuilder extends ComponentBuilder<ButtonBuilder> {
    protected AnAction action;
    protected String title = null;
    protected Image icon;

    @Override
    public ButtonBuilder fromAnAction(AnAction action) {
        if(action.getTemplatePresentation().getText() == null && action.getTemplatePresentation().getIcon() == null) {
            throw new RuntimeException("Invalid action.");
        }

        if(action.getTemplatePresentation().getIcon() == null) {
            this.title(action.getTemplatePresentation().getText());
        }
        else {
            this.icon(action.getTemplatePresentation().getIcon());
        }
        this.action(action);
        this.identifier(action.toString());
        return this;
    }

    public ButtonBuilder title(String title) {
        this.title = title;
        return this;
    }

    public ButtonBuilder icon(BufferedImage image) {
        return this.icon(new Image(getImgBytes(image)));
    }

    public ButtonBuilder icon(Icon icon) {
        return this.icon(iconToImage(icon));
    }

    public ButtonBuilder icon(Image icon) {
        this.icon = icon;
        return this;
    }

    public ButtonBuilder action(AnAction action) {
        this.action = action;
        return this;
    }

    static byte [] getImgBytes(BufferedImage image) {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        try {
            ImageIO.write(image, "PNG", baos);
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
        return baos.toByteArray();
    }

    static BufferedImage iconToImage(Icon icon) {
        BufferedImage image = createImage(
            icon.getIconWidth(),
            icon.getIconHeight(),
            BufferedImage.TYPE_INT_ARGB
        );
        Graphics g = image.createGraphics();
        // paint the Icon to the BufferedImage.
        icon.paintIcon(null, g, 0,0);
        g.dispose();
        return image;
    }

    public TouchBarButton build() {
        TouchBarButton touchBarButton = new TouchBarButton();
        touchBarButton.setImage(this.icon);
        touchBarButton.setTitle(this.title);
        touchBarButton.setBezelColor(Color.CONTROL_COLOR);
        touchBarButton.setAction(touchBarView ->
            ApplicationManager.getApplication()
                .invokeLater(() -> this.runAction(this.action))
        );
        return touchBarButton;
    }

    @Override
    public void add() {
        TouchBarButton touchBarButton = this.build();

        this.touchBar.addItem(
            new TouchBarItem(this.identifier, touchBarButton)
        );

        this.touchBar.addItemListener(new TouchBar.ItemListener() {
            @Override
            public String getActionId() {
                return ActionManager.getInstance().getId(ButtonBuilder.this.action);
            }

            @Override
            public PropertyChangeListener getPropertyChangeListener() {
                return evt -> {
                    System.out.println("something changed");
                    System.out.println("property: " + evt.getPropertyName() );
                    System.out.println("new value: "+ evt.getNewValue());
                    if(evt.getPropertyName().equals("icon") && evt.getNewValue() != null) {
                        ButtonBuilder.this.icon((Icon) evt.getNewValue());
                        touchBarButton.setImage(ButtonBuilder.this.icon);
                    }
                };
            }
        });
    }
}
