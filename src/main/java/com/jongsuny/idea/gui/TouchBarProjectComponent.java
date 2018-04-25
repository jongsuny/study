package com.jongsuny.idea.gui;

import com.intellij.openapi.components.ProjectComponent;
import com.intellij.openapi.project.Project;

public class TouchBarProjectComponent implements ProjectComponent {

    protected Project project;

    public TouchBarProjectComponent(Project project) {
        this.project = project;
    }

    @Override
    public void projectOpened() {
        TouchBar touchBar = TouchBar.getInstance(project);
        touchBar.refresh();
    }
}
