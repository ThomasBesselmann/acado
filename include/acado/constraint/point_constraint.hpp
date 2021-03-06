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
 *    \file include/acado/constraint/point_constraint.hpp
 *    \author Boris Houska, Hans Joachim Ferreau
 *
 */


#ifndef ACADO_TOOLKIT_POINT_CONSTRAINT_HPP
#define ACADO_TOOLKIT_POINT_CONSTRAINT_HPP


#include <acado/constraint/constraint_element.hpp>


BEGIN_NAMESPACE_ACADO


/** 
 *	\brief Stores and evaluates pointwise constraints within optimal control problems.
 *
 *	\ingroup BasicDataStructures
 *
 *	The class PointConstraint allows to manage and evaluate pointwise 
 *	constraints within optimal control problems.
 *
 *	\author Boris Houska, Hans Joachim Ferreau
 */
class PointConstraint : public ConstraintElement{

    //
    // PUBLIC MEMBER FUNCTIONS:
    //
    public:

        /** Default constructor. */
        PointConstraint( );

        /** Default constructor. */
        PointConstraint( const Grid& grid_, int point_index_ );

        /** Copy constructor (deep copy). */
        PointConstraint( const PointConstraint& rhs );

        /** Destructor. */
        virtual ~PointConstraint( );

        /** Assignment operator (deep copy). */
        PointConstraint& operator=( const PointConstraint& rhs );



        /**  Adds a point-constraint component.
         *   \return SUCCESSFUL_RETURN
         *           RET_MEMBER_NOT_INITIALISED  (if the ConstraintElement::fcn is not initialized)
         */
        returnValue add( const double lb_, const Expression& arg, const double ub_  );



// =======================================================================================
//
//                                   EVALUATION ROUTINES
//
// =======================================================================================


        /** Evaluates all components in this constraint and stores the \n
          * residuum.                                                  \n
          *                                                            \n
          * \return SUCESSFUL_RETURN                                   \n
          */
        returnValue evaluate( const OCPiterate& iter );


        /** Evaluates the sensitivities of all components in this      \n
          * constraint. Note that the seed can be defined via the base \n
          * class ConstraintElement.                                   \n
          *                                                            \n
          * \return SUCESSFUL_RETURN                                   \n
          */
        returnValue evaluateSensitivities();



        /** Evaluates the sensitivities and Hessian.                   \n
          *                                                            \n
          * \return SUCESSFUL_RETURN                                   \n
          */
        returnValue evaluateSensitivities( const Matrix &seed, BlockMatrix &hessian );



//  =========================================================================

        /** returns the number of constraints */
        inline int getNC() const;


		/** returns whether object only comprises box constraints. */
		inline BooleanType isBoxConstraint( ) const;


    /** Writes a special copy of the bounds that is needed within the
     *  OptimizationAlgorithm into the optimization variables.
     */
    returnValue getBounds( const OCPiterate& iter );



    // PROTECTED FUNCTIONS:
    // --------------------
	protected:

        /** only for internal use (routine which computes a part of the block
         *  matrix needed for forward differentiation.) */
        returnValue computeForwardSensitivityBlock( int offset, int offset2, Matrix *seed );



    // DATA MEMBERS:
    // -------------

    protected:

       int         point_index;   /**< index of the constraint relative to the constraint grid */

       int              nb    ;   /**< counts the number of simple point bounds                */
       VariableType    *var   ;   /**< variable types                                          */
       int             *index ;   /**< component of the variable                               */
       double          *blb   ;   /**< lower bounds                                            */
       double          *bub   ;   /**< upper bounds                                            */
};


CLOSE_NAMESPACE_ACADO



#include <acado/constraint/point_constraint.ipp>


#endif  // ACADO_TOOLKIT_POINT_CONSTRAINT_HPP

/*
 *    end of file
 */
