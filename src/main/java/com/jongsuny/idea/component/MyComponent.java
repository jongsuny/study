package com.jongsuny.idea.component;


import com.intellij.openapi.components.ApplicationComponent;

import com.intellij.openapi.ui.Messages;

import org.jetbrains.annotations.NotNull;


/**
 * My Component
 * <p>
 * User: cdai
 * <p>
 * Date: 13-11-4
 * <p>
 * Time: 上午10:08
 */

public class MyComponent implements ApplicationComponent {

    public MyComponent() {

    }

    public void initComponent() {
        // TODO: insert component initialization logic here
    }

    public void disposeComponent() {
        // TODO: insert component disposal logic here
    }

    @NotNull
    public String getComponentName() {
        return "MyComponent";
    }

    public void sayHello() {
        // Show dialog with message
        Messages.showMessageDialog(
                "Hello World!",
                "Sample",
                Messages.getInformationIcon()
        );
    }
}