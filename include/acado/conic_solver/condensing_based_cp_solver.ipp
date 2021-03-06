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
 *    \file include/acado/conic_solver/condensing_based_cp_solver.ipp
 *    \author Boris Houska, Hans Joachim Ferreau
 */


//
// PUBLIC MEMBER FUNCTIONS:
//



BEGIN_NAMESPACE_ACADO


inline uint CondensingBasedCPsolver::getNX( ) const
{
	return iter.getNX();
}


inline uint CondensingBasedCPsolver::getNXA( ) const
{
	return iter.getNXA();
}


inline uint CondensingBasedCPsolver::getNP( ) const
{
	return iter.getNP();
}

inline uint CondensingBasedCPsolver::getNU( ) const
{
	return iter.getNU();
}


inline uint CondensingBasedCPsolver::getNW( ) const
{
	return iter.getNW();
}


inline uint CondensingBasedCPsolver::getNC( ) const
{
	return nConstraints;
}


inline uint CondensingBasedCPsolver::getNF( ) const
{
	return getNX() + getNumPoints( )*getNXA() + getNP() + (getNumPoints( )-1)*getNU() + (getNumPoints( )-1)*getNW();
}


inline uint CondensingBasedCPsolver::getNA( ) const
{
	return getNC() + (getNumPoints( )-1)*getNX();
}


inline uint CondensingBasedCPsolver::getNumPoints( ) const
{
	return iter.getNumPoints();
}


inline BooleanType CondensingBasedCPsolver::areRealTimeParametersDefined( ) const
{
	if ( ( deltaX.isEmpty( ) == BT_TRUE ) && ( deltaP.isEmpty( ) == BT_TRUE ) )
		return BT_FALSE;
	else
		return BT_TRUE;
}


CLOSE_NAMESPACE_ACADO

// end of file.
