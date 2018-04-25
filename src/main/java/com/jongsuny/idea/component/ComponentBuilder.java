package com.jongsuny.idea.component;

import com.intellij.ide.ui.customization.CustomisedActionGroup;
import com.intellij.openapi.actionSystem.ActionPlaces;
import com.intellij.openapi.actionSystem.AnAction;
import com.intellij.openapi.actionSystem.Separator;
import com.intellij.openapi.actionSystem.ex.ActionManagerEx;
import com.jongsuny.idea.gui.TouchBar;

import java.awt.*;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;

import static java.awt.event.ComponentEvent.COMPONENT_FIRST;

public abstract class ComponentBuilder<BUILDER extends ComponentBuilder> {

    protected TouchBar touchBar;

    protected String identifier;

    public ComponentBuilder(TouchBar touchBar) {
        this.touchBar = touchBar;
    }

    public ComponentBuilder() {}

    public ComponentBuilder touchBar(TouchBar touchBar) {
         this.touchBar = touchBar;
         return this;
    }

    public ComponentBuilder identifier(String identifier) {
        this.identifier = identifier;
        return this;
    }

    public static ComponentBuilder fromAction(AnAction anAction) {
        if(anAction instanceof Separator) {
            return new SeparatorBuilder().fromAnAction(anAction);
        }
        else if(anAction instanceof CustomisedActionGroup) {
            return new PopoverBuilder().fromAnAction(anAction);
        }
        else {
            return new ButtonBuilder().fromAnAction(anAction);
        }
    }

    public abstract BUILDER fromAnAction(AnAction action);

    public abstract void add();

    protected void runAction(AnAction anAction) {


        final ActionManagerEx actionManagerEx = ActionManagerEx.getInstanceEx();
        final KeyboardFocusManager focusManager=KeyboardFocusManager.getCurrentKeyboardFocusManager();
        final Component focusOwner = focusManager.getFocusedWindow();

        final InputEvent ie = new KeyEvent(focusOwner, COMPONENT_FIRST, System.currentTimeMillis(), 0, 0, '\0');
        actionManagerEx.tryToExecute(anAction, ie, focusOwner, ActionPlaces.TOOLBAR, false);
    }
}
