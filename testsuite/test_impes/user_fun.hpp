/* -*- mode: c++ -*-

  This file is part of the LifeV Applications.

  Author(s):  A. Fumagalli  <alessio.fumagalli@mail.polimi.it>
       Date: 2010-07-29

  Copyright (C) 2010 EPFL, Politecnico di Milano

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA
*/

/**
   @file user_fun.hpp
   @author A. Fumagalli <alessio.fumagalli@mail.polimi.it>
   @date 2010-07-29
*/

#ifndef __user_fun_H
#define __user_fun_H 1

#include <vector>

#include <life/lifecore/life.hpp>
#include <life/lifecore/application.hpp>
#include <life/lifearray/tab.hpp>

using namespace LifeV;

// ===================================================
//! User functions for the pressure equation
// ===================================================
namespace dataProblem
{

// Inverse of permeability matrix
Matrix pressurePermeability( const Real& /*t*/, const Real& x, const Real& y, const Real& z, const std::vector<Real>& u );

// Source term
Real pressureSource( const Real& /*t*/, const Real& x, const Real& y, const Real& /*z*/, const ID& /*icomp*/);

// Boundary condition of Dirichlet
Real pressureDirichlet1( const Real& /* t */, const Real& x, const Real& y, const Real& z, const ID& /*icomp*/);

// Boundary condition of Dirichlet
Real pressureDirichlet2( const Real& /* t */, const Real& x, const Real& y, const Real& z, const ID& /*icomp*/);

// Boundary condition of Dirichlet
Real pressureDirichlet3( const Real& /* t */, const Real& x, const Real& y, const Real& z, const ID& /*icomp*/);

// Boundary condition of Neumann
Real pressureNeumann( const Real& /* t */, const Real& x, const Real& y, const Real& z, const ID& icomp);

// Boundary condition of Robin
Real pressureMixte( const Real& /* t */, const Real& x, const Real& y, const Real& z, const ID& /*icomp*/);

// ===================================================
//! User functions for the saturation equation
// ===================================================

// Inverse of permeability matrix
Matrix saturationPermeability( const Real& t, const Real& x, const Real& y, const Real& z, const std::vector<Real>& u );

// Physical flux function
Vector saturationPhysicalFlux( const Real& /*t*/, const Real& x, const Real& y, const Real& z, const Real& u );

// First derivative in u of the physical flux function
Vector saturationFirstDerivativePhysicalFlux( const Real& /*t*/, const Real& x, const Real& y, const Real& z, const Real& u );

// Source term
Real saturationSource( const Real& /*t*/, const Real& x, const Real& y, const Real& /*z*/, const ID& /*icomp*/);

// Initial condition
Real saturationInitialCondition( const Real& /* t */, const Real& x, const Real& y, const Real& z, const ID& /*icomp*/ );

// Boundary condition of Dirichlet
Real saturationDirichlet1( const Real& /* t */, const Real& x, const Real& y, const Real& z, const ID& /*icomp*/);

// Boundary condition of Dirichlet
Real saturationDirichlet2( const Real& /* t */, const Real& x, const Real& y, const Real& z, const ID& /*icomp*/);

// Boundary condition of Dirichlet
Real saturationDirichlet3( const Real& /* t */, const Real& x, const Real& y, const Real& z, const ID& /*icomp*/);

// Boundary condition of Neumann
Real saturationNeumann( const Real& /* t */, const Real& x, const Real& y, const Real& z, const ID& icomp);

// Boundary condition of Robin
Real saturationMixte( const Real& /* t */, const Real& x, const Real& y, const Real& z, const ID& /*icomp*/);

}

#endif /* __user_fun_H */