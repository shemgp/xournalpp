/*
 * Xournal++
 *
 * Toolbar definitions model
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv3
 */

#pragma once

#include <glib.h>
#include <StringUtils.h>
#include <XournalType.h>
#include <vector>

#include "ToolbarEntry.h"

class ToolbarData
{
public:
	ToolbarData(bool predefined);
	ToolbarData(const ToolbarData& data);
	virtual ~ToolbarData();

public:
	string getName();
	void setName(string name);
	string getId();
	void setId(string id);
	bool isPredefined();

	void load(GKeyFile* config, const char* group);
	void saveToKeyFile(GKeyFile* config);

	// Editing API
	int insertItem(string toolbar, string item, int position);
	bool removeItemByID(string toolbar, int id);

private:
	XOJ_TYPE_ATTRIB;

	string id;
	string name;
	std::vector<ToolbarEntry> contents;

	bool predefined;

	friend class ToolbarModel;
	friend class ToolMenuHandler;
};
