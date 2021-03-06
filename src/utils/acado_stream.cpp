/*
 *    This file is part of ACADO Toolkit.
 *
 *    ACADO Toolkit -- A Toolkit for Automatic Control and Dynamic Optimization.
 *    Copyright (C) 2008-2013 by Boris Houska, Hans Joachim Ferreau,
 *    Milan Vukov, Rien Quirynen, KU Leuven.
 *    Developed within the Optimization in Engineering Center (OPTEC)
 *    under supervision of Moritz Diehl. All rights reserved.
 *
 *    ACADO Toolkit is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with ACADO Toolkit; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/**
*    \file   src/utils/acado_stream.cpp
*    \author Boris Houska, Hans Joachim Ferreau
*    \date   2010
*/


#include <acado/utils/acado_stream.hpp>


BEGIN_NAMESPACE_ACADO


Stream::Stream(                     ):String(       ){ }
Stream::Stream( const char   *name_ ):String( name_ ){ }
Stream::Stream( const double &val_  ):String( val_  ){ }
Stream::Stream( const int    &val_  ):String( val_  ){ }
Stream::Stream( const Stream& arg   ):String( arg   ){ }


Stream& Stream::operator=( const Stream& arg ){

    if( this != &arg ){

        String::operator=(arg);
    }
    return *this;
}


Stream& Stream::operator=( const char *name_ ){

    String::operator=( name_ );
    return *this;
}


Stream::~Stream(){ }


Stream& Stream::operator<<( const Stream& arg ){

    operator+=(arg);
    return *this;
}


Stream& Stream::operator<<( const char* arg ){

    operator+=(arg);
    return *this;
}


Stream& Stream::operator<<( const double& arg ){

    return operator<<( Stream(arg) );
}

Stream& Stream::operator<<( const int& arg ){

    return operator<<( Stream(arg) );
}

Stream& Stream::operator<<( const uint& arg ){

    return operator<<( Stream( (int) arg) );
}

Stream& Stream::operator<<( const String& arg ){

    String::operator+=(arg);
    return *this;
}


returnValue operator<<( FILE *file, const Stream &stream ){

    return stream.print( file );
}



CLOSE_NAMESPACE_ACADO

// end of file.
