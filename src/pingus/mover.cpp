//  Pingus - A free Lemmings clone
//  Copyright (C) 1999 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "pingus/mover.hpp"

Mover::Mover(World* const world_arg, const Vector3f& pos_arg)
  : world(world_arg),
    pos(pos_arg),
    remaining_move(0.0f, 0.0f, 0.0f),
    collision(false)
{
}

Mover::~Mover ()
{
}

Vector3f Mover::get_pos() const
{
  return pos;
}

Vector3f Mover::remaining() const
{
  return remaining_move;
}

bool Mover::collided() const
{
  return collision;
}

void Mover::reset(World* const new_world, const Vector3f& new_pos) {
	//world = new_world;
	pos = new_pos;
	remaining_move = Vector3f(0, 0, 0);
	collision = false;
}

/* EOF */
