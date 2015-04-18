/*
 * Xournal++
 *
 * List of unused colors for toolbar customisation
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv3
 */

#pragma once

#include <XournalType.h>
#include <StringUtils.h>

#include "../../XojColor.h"

typedef std::vector<XojColor*> XojColorVector;

class CustomizeableColorList
{
public:
	CustomizeableColorList();
	virtual ~CustomizeableColorList();

public:
	XojColorVector* getPredefinedColors();

private:
	void addPredefinedColor(int color, string name);

private:
	XOJ_TYPE_ATTRIB;

	XojColorVector colors;

};
