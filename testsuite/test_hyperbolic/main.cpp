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
/* ========================================================

Simple hyperbolic test with Dirichlet, Neumann and Robin boundary conditions

Solve the problem

               div u - f = 0            in \Omega

               K^{-1} u + \nabla p = 0  in \Omega

*/


/**
   @file main.hpp
   @author A. Fumagalli <alessio.fumagalli@mail.polimi.it>
   @date 2010-07-29
*/


// ===================================================
//! Includes
// ===================================================

#include <Epetra_ConfigDefs.h>
#ifdef EPETRA_MPI
#include <mpi.h>
#include <Epetra_MpiComm.h>
#else
#include <Epetra_SerialComm.h>
#endif

#include <boost/program_options.hpp>

#include <life/lifecore/life.hpp>
#include <life/lifecore/application.hpp>

#include "hyperbolic.hpp"


// ===================================================
//! Program information
// ===================================================

LifeV::AboutData
makeAbout()
{
    LifeV::AboutData about( "Test Hyperbolic" ,
                            "LifeV Test Hyperbolic" ,
                            "1.0",
                            "Hyperbolic test case",
                            LifeV::AboutData::License_GPL,
                            "Copyright (c) 2010 MOX");

    about.addAuthor("Alessio Fumagalli", "Developer", "alessio.fumagalli@mail.polimi.it", "");

    return about;
}

// ===================================================
//! Namespaces
// ===================================================
using namespace LifeV;

// ===================================================
//! Main
// ===================================================
int main(int argc, char** argv)
{

#ifdef HAVE_MPI
    MPI_Init(&argc, &argv);
    std::cout << "MPI Initialization" << std::endl;
#endif


    LifeV::po::options_description desc("Specific options");
    desc.add_options()("file,f", LifeV::po::value<std::string>()->default_value( "data" ), "data file name");

    // Error of the problem
    LifeV::Real error(0);
    // Error known
    const LifeV::Real errorKnown( 0.200340988220163 );
    // Tollerance between the error and the errorKnown
    const LifeV::Real tollerance( 1e-8 );

    hyperbolic Hyperbolic( argc, argv, makeAbout(), desc );
    error = Hyperbolic.run();


#ifdef HAVE_MPI
    MPI_Finalize();
    std::cout << "MPI Finalization" << std::endl;
#endif

    if ( abs( error - errorKnown ) > tollerance )
        return ( EXIT_FAILURE );
    else
        return ( EXIT_SUCCESS );
}
