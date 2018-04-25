package com.jongsuny.idea.gui;

import com.intellij.openapi.options.Configurable;
import com.intellij.openapi.options.ConfigurationException;
import com.jongsuny.idea.setting.FormatForm;
import com.jongsuny.idea.setting.FormatSetting;
import com.jongsuny.idea.setting.Settings;
import org.jetbrains.annotations.Nls;
import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

import javax.swing.*;

public class SettingsGui implements Configurable {
    private Settings formatForm;
    private FormatSetting formatSetting = FormatSetting.getInstance();

    public SettingsGui() {
    }

    @NotNull
    public String getId() {
        return "DocFormat";
    }

    @Nls
    public String getDisplayName() {
        return this.getId();
    }

    @Nullable
    public String getHelpTopic() {
        return this.getId();
    }

    @Nullable
    public JComponent createComponent() {
        if (null == this.formatForm) {
            this.formatForm = new Settings();
        }
        return this.formatForm.mainPanel;
    }

    public boolean isModified() {
        return false;
    }

    public void apply() throws ConfigurationException {
    }

    public void reset() {
    }
}
