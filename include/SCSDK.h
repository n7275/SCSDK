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

enum scsdk_entity_type{
  ELECTRIC_PUMP,
  TANK,
  PIPE
};

//Main entity type
struct scsdk_entity{
  int ID;
  int flags;
  enum scsdk_entity_type type;
};

// Structure containing all entities
typedef struct{
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

union scsdk_linkage_property{
  int direction;
  double amount;
  bool is_active;
  long l_int_property;
  double d_double_property;
};

enum scsdk_linkage_type{
  is_a_member_of
};
  

struct scsdk_linkage_table{
  struct entity* pEntA;
  struct entity* pEntB;
  struct scsdk_linkage_type connection_type;
  struct scsdk_linkage_property connection_property;
};


/*****************************************************************************
 All component types defined below.
******************************************************************************/


  
#endif
