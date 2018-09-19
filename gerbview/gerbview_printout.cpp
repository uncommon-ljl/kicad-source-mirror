/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2016 Jean-Pierre Charras, jp.charras at wanadoo.fr
 * Copyright (C) 1992-2016 KiCad Developers, see AUTHORS.txt for contributors.
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

/**
 * @file printout_control.cpp
 * @brief Board print handler implementation file.
 */


#include <fctsys.h>
#include <pgm_base.h>
#include <gr_basic.h>
#include <class_drawpanel.h>
#include <base_units.h>
#include <base_screen.h>

#include <gerbview_frame.h>
#include <gerber_file_image.h>
#include <gerber_file_image_list.h>

#include "gerbview_printout.h"

#include <gal/gal_print.h>
#include <view/view.h>
#include <gerbview_painter.h>


GERBVIEW_PRINTOUT::GERBVIEW_PRINTOUT( GBR_LAYOUT* aLayout, const PRINT_PARAMETERS& aParams,
        const KIGFX::VIEW* aView, const wxSize& aSheetSize, const wxString& aTitle ) :
    BOARD_PRINTOUT( aParams, aView, aSheetSize, aTitle )
{
    m_layout = aLayout;
}


bool GERBVIEW_PRINTOUT::OnPrintPage( int aPage )
{
    // in gerbview, draw layers are always printed on separate pages
    // because handling negative objects when using only one page is tricky
    m_PrintParams.m_Flags = aPage;

    // The gerber filename of the page to print will be printed to the worksheet.
    // Find this filename:
    // Find the graphic layer number for the page to print
    std::vector<int> printList = m_layout->GetPrintableLayers();

    if( printList.size() < 1 )      // Should not occur
        return false;

    int graphiclayer = printList[aPage-1];
    GERBER_FILE_IMAGE_LIST& gbrImgList = GERBER_FILE_IMAGE_LIST::GetImagesList();
    GERBER_FILE_IMAGE* gbrImage = gbrImgList.GetGbrImage( graphiclayer );
    wxString gbr_filename;

    if( gbrImage )
        gbr_filename = gbrImage->m_FileName;

    DrawPage( gbr_filename, aPage, m_PrintParams.m_PageCount );

    return true;
}


EDA_RECT GERBVIEW_PRINTOUT::getBoundingBox()
{
    return m_layout->ComputeBoundingBox();
}


std::unique_ptr<KIGFX::PAINTER> GERBVIEW_PRINTOUT::getPainter( KIGFX::GAL* aGal )
{
    return std::unique_ptr<KIGFX::PAINTER>( new KIGFX::GERBVIEW_PAINTER( aGal ) );
}
