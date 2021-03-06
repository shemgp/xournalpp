/*
 * Xournal++
 *
 * Settings Dialog
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "control/settings/Settings.h"
#include "gui/GladeGui.h"

#include <XournalType.h>

#include <vector>

class ButtonConfigGui;

class SettingsDialog : public GladeGui
{
public:
	SettingsDialog(GladeSearchpath* gladeSearchPath, Settings* settings);
	virtual ~SettingsDialog();

public:
	virtual void show(GtkWindow* parent);

	void save();

	void setDpi(int dpi);

	void toolboxToggled();

private:
	void load();
	void loadCheckbox(const char* name, gboolean value);
	bool getCheckbox(const char* name);

	string updateHideString(string hidden, bool hideMenubar, bool hideSidebar);

	void initMouseButtonEvents();
	void initMouseButtonEvents(const char* hbox, int button, bool withDevice = false);

	static gboolean zoomcallibSliderChanged(GtkRange* range, GtkScrollType scroll, gdouble value, SettingsDialog* dlg);

	static void toolboxToggledCallback(GtkToggleButton* togglebutton, SettingsDialog* sd);

private:
	XOJ_TYPE_ATTRIB;

	Settings* settings;
	GtkWidget* callib;
	int dpi;

	std::vector<ButtonConfigGui*> buttonConfigs;
};
