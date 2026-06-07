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

  2026-06-06 MWH  Initial design implimentation


  ---------------------------------------------------------------------------

                        ____   ____ ____  ____  _  __
                       / ___| / ___/ ___||  _ \| |/ /
                       \___ \| |   \___ \| | | | ' / 
                        ___) | |___ ___) | |_| | . \ 
                       |____/ \____|____/|____/|_|\_\

                           Systems-Components SDK

 SCSDK is heavily inspired by the SPSDK (Systems and Panel SDK) library
 for Orbiter Spaceflight Simulator, written by Radu054 and heavily modified
 by the NASSP development from 2003-2026+. This library attempts to
 address many of the chalenges and lessons-learned that the NASSP
 developers in their efforts to simulate the hardware and systems of
 the Apollo Program's spacecraft.

*******************************************************************************/

ifndef SCSDK
#define SCSDK

#define NAME_LENGTH 64;
#define MAX_SWITCH_STATES 8;

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
  char[NAME_LENGTH] name;
};

// Structure containing all entities
typedef struct{
  entity* entities;
  unsigned int num_entities;
} SCSDKInstance;


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
  nil,
  is_a_member_of,
  propagate_bidirectional,
  propagate_A2B,
  propagate_B2A,
  wired_to,
  fluid_connection,
  time_propagate,
  external
};

union scsdk_component;

struct scsdk_linkage_table{
  union A {
    struct scsdk_entity* p_ent_A;
    union scsdk_component* p_comp_A;
  };

  union B {
    struct scsdk_entity* p_ent_B;
    union scsdk_component* p_comp_B;
  };
  
  struct scsdk_linkage_type connection_type;
  struct scsdk_linkage_property connection_property;
};

/*****************************************************************************
 Dispatcher and Worker Function Definitions
******************************************************************************/


int scsdk_update_connections(struct scsdk_linkage_table* p_linkage_table){
  int linkage_table_index = 0;
  int result = 0;
  while(p_linkage_table){
    switch(p_linkage_table[linkage_table_index]->connection_type){
    case:nil
	p_linkage_table = NULL;
      result = -1;
      break;
    case:is_a_member_of
	result = 0;
      break;
    case:propagate_bidirectional
	result = 1;
      break;
    case:propagate_A2B
	result = 2;
      break;
    case:propagate_B2A
	result = 3;
      break;
    case:wired_to
	result = 4;
      break;
    case:fluid_connection
	result = 5;
      break;
    case:time_propagate
	result = 6;
      break;
    case:external
	result = 7;
      break;
    default:
      p_linkage_table = NULL;
      result = -2;
      break;
    }
    ++linkage_table_index;
  }
  return result;
}

/*****************************************************************************
 All component types defined below.
******************************************************************************/

struct electrical_state_primitive{
  double voltage;       // Volts
  double current;       // Amps
  double frequency;     // Hertz
  double phase_angle;   // Radians
};

struct switch_state_primitive{
  unsigned state;
  bool active [MAX_SWITCH_STATES];
};

union scsdk_component{
  struct electrical_state_primitive e_state;
};
  
#endif
