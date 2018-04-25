package com.jongsuny.idea.action;

import com.intellij.openapi.actionSystem.AnAction;
import com.intellij.openapi.actionSystem.AnActionEvent;
import com.intellij.openapi.application.Application;
import com.intellij.openapi.application.ApplicationManager;
import com.jongsuny.idea.component.MyComponent;
import com.jongsuny.idea.setting.Settings;

public class TestAction extends AnAction {
    public TestAction() {
        // Set the menu item name.
        super("Text _Boxes");
        // Set the menu item name, description and icon.
        // super("Text _Boxes","Item description",IconLoader.getIcon("/Mypackage/icon.png"));
    }

    @Override
    public void actionPerformed(AnActionEvent event) {
//        Project project = event.getData(PlatformDataKeys.PROJECT);
//        String txt= Messages.showInputDialog(project, "What is your name?", "Input your name", Messages.getQuestionIcon());
//        Messages.showMessageDialog(project, "Hello, " + txt + "!\n I am glad to see you.", "Information", Messages.getInformationIcon());
        Application application = ApplicationManager.getApplication();
        MyComponent myComponent = application.getComponent(MyComponent.class);
        myComponent.sayHello();
        Settings settings;
    }
}
