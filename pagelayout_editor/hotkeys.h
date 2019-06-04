/**
 * @file pagelayout_editor/hotkeys.h
 */

/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2013 CERN
 * Copyright (C) 2016-2019 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef PL_EDITOR_KOTKEYS_H_
#define PL_EDITOR_KOTKEYS_H_

#include <hotkeys_basic.h>

// List of hot keys id.
// see also enum common_hotkey_id_command in hotkeys_basic.h
// for shared hotkeys id
enum hotkey_id_command {
    HK_PL_EDITOR_START = HK_COMMON_END,
    HK_MOVE,
    HK_PL_EDITOR_END
};

// List of hotkey descriptors for PlEditor.
extern struct EDA_HOTKEY_CONFIG PlEditorHotkeysDescr[];

#endif		// PL_EDITOR_KOTKEYS_H_
