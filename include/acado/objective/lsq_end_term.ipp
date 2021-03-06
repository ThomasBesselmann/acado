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
 *    \file include/acado/objective/lsq_end_term.ipp
 *    \author Boris Houska, Hans Joachim Ferreau
 *
 */



BEGIN_NAMESPACE_ACADO



//
// PUBLIC MEMBER FUNCTIONS:
//


inline returnValue LSQEndTerm::init( const Grid&     grid_,
                                     const Matrix      &S_,
                                     const Function&    m_,
                                     const Vector      &r_  ){

    grid = grid_;
    fcn  = m_   ;
    S    = S_   ;
    r    = r_   ;

    return SUCCESSFUL_RETURN;
}


inline BooleanType LSQEndTerm::isQuadratic(){

    if( fcn.isAffine() == BT_FALSE ) return BT_FALSE;
    return BT_FALSE;
}


inline returnValue LSQEndTerm::setReference( const Vector &ref ){

    r = ref;
    return SUCCESSFUL_RETURN;
}



CLOSE_NAMESPACE_ACADO

// end of file.
