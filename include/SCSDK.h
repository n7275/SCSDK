/*******************************************************************************

                 Systems Component Software Development Kit


  This file is part of SCSDK
  Copyright 2025 Matthew Hume


  SCSDK is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  SCSDK is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with SCSDK; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  See <URL>
  for more details.

*******************************************************************************/

enum entityType{
  ELECTRIC_PUMP,
  TANK,
  PIPE
};

//Main entity type
typedef struct {
  int ID;
  entityType type;
  int flags;
} entity;

// Structure containing all entities
typedef struct {
  entity* entities;
  unsigned int num_entities;
} SCSDKInstance;

int SCSDK_Update_Systems(double dt, SCSDKInstance* pSCSDK){
  for(int index; index < pSCSDK->num_entities; intex++){
    //do update stuff
  }
}

/*****************************************************************************
 All component types defined below.
******************************************************************************/

#define MAX_ELEC_I_O = 4;
typedef struct {
  int ID;
  double inputVoltage[MAX_ELEC_I_O];
  double outputVoltage[MAX_ELEC_I_O];
} electricalComponent;

  
