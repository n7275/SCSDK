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

  See http://mwhume.space/scsdk
  for more details.

*******************************************************************************/

ifndef SCSDK
#define SCSDK

typedef enum scsdk_entity_type{
  ELECTRIC_PUMP,
  TANK,
  PIPE
} scsdk_entity_type_t;

//Main entity type
typedef struct entity{
  int ID;
  entityType type;
  int flags;
} entity_t;

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
 Linkage Table Definition
******************************************************************************/

typedef union scsdk_linkage_property{
  int direction;
  double amount;
  bool is_active;
  long l_int_property;
  double d_double_property;
} scsdk_linkage_property_t;

typedef enum scsdk_linkage_type{
  is_a_member_of;
  
} scsdk_linkage_type_t;

typedef struct scsdk_linkage_table_struct{
  entity* pEntA;
  entity* pEntB;
  scsdk_linkage_type_t connection_type;
  scsdk_linkage_property_t connection_property;
}scsdk_linkage_table_struct_t;


/*****************************************************************************
 All component types defined below.
******************************************************************************/




//bad example, remove
/*
#define MAX_ELEC_I_O = 4;
typedef struct {
  int ID;
  double inputVoltage[MAX_ELEC_I_O];
  double outputVoltage[MAX_ELEC_I_O];
} electricalComponent;
*/
  
#endif
