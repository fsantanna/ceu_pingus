//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
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

#include "pingus/components/smallmap.hpp"

#include "pingus/components/playfield.hpp"
#include "pingus/pingu_holder.hpp"
#include "pingus/server.hpp"
#include "pingus/smallmap_image.hpp"
#include "pingus/world.hpp"

#include "ceuvars.h"

SmallMap::SmallMap(Server* server_, Playfield* playfield_, const Rect& rect_) :
  RectComponent(rect_), 
  server(server_),
  playfield(playfield_),
  exit_sur(),
  entrance_sur(),
  image(),
  scroll_mode(),
  has_focus(),
  gc_ptr(0)
{ 
  image = std::unique_ptr<SmallMapImage>(new SmallMapImage(server, rect.get_width(), rect.get_height()));

  scroll_mode = false;

  SmallMap* self = this;
  ceu_out_go(&CEUapp, CEU_IN_NEW_SMALLMAP, &self);
}

SmallMap::~SmallMap() {
  SmallMap* self = this;
  ceu_out_go(&CEUapp, CEU_IN_DELETE_SMALLMAP, &self);
}

void
SmallMap::draw(DrawingContext& gc)
{
  // FIXME: This is potentially dangerous, since we don't know how
  // long 'gc' will be alive. Should use a DrawingContext for caching.
  gc_ptr = &gc;

  World* const& world  = server->get_world();
  
  Vector2i of = playfield->get_pos();
  Rect view_rect;

  if (world->get_width() > gc.get_width())
  {
    int rwidth = int(gc.get_width()  * rect.get_width()  / world->get_width());
    view_rect.left  = rect.left + (of.x * rect.get_width()  / world->get_width()) - rwidth/2;
    view_rect.right = view_rect.left + rwidth;
  }
  else
  {
    view_rect.left  = rect.left;
    view_rect.right = rect.left + rect.get_width();
  }

  if (world->get_height() > gc.get_height())
  {
    int rheight = int(gc.get_height() * rect.get_height() / world->get_height());
    view_rect.top    = rect.top + (of.y * rect.get_height() / world->get_height()) - rheight/2;
    view_rect.bottom = view_rect.top + rheight;
  }
  else
  {
    view_rect.top    = rect.top;
    view_rect.bottom = rect.top + rect.get_height();
  }
  
  gc.draw(image->get_surface(), Vector2i(rect.left, rect.top));
  gc.draw_rect(view_rect, Color(0, 255, 0));  

  SmallMap* self = this;
  ceu_out_go(&CEUapp, CEU_IN_SMALLMAP_DRAW, &self);

  gc_ptr = 0;
}

void
SmallMap::update (float delta)
{
  image->update(delta);
}

void
SmallMap::draw_sprite(Sprite sprite, Vector3f pos)
{
  World* world = server->get_world();
  float x = static_cast<float>(rect.left) + (pos.x * static_cast<float>(rect.get_width())  / static_cast<float>(world->get_width()));
  float y = static_cast<float>(rect.top)  + (pos.y * static_cast<float>(rect.get_height()) / static_cast<float>(world->get_height()));

  gc_ptr->draw(sprite, Vector3f(x, y));
}

bool
SmallMap::is_at (int x, int y)
{
  return (x > rect.left && x < rect.left + static_cast<int>(rect.get_width())
          && y > rect.top && y < rect.top + static_cast<int>(rect.get_height()));
}

void
SmallMap::on_pointer_move (int x, int y)
{
  int cx, cy;
  World* world = server->get_world();

  if (scroll_mode)
  {
    cx = (x - rect.left) * static_cast<int>(world->get_width()  / rect.get_width());
    cy = (y - rect.top) * static_cast<int>(world->get_height() / rect.get_height());

    playfield->set_viewpoint(cx, cy);
  }
}

void
SmallMap::on_primary_button_press (int x, int y)
{
  scroll_mode = true;

  // set view to the given COs
  int cx, cy;
  World* world = server->get_world();
  cx = (x - rect.left) * int(world->get_width()) / rect.get_width();
  cy = (y - rect.top) * int(world->get_height()) / rect.get_height();
  playfield->set_viewpoint(cx, cy);
}

void
SmallMap::on_primary_button_release(int x, int y)
{
  scroll_mode = false;
}

void
SmallMap::on_pointer_enter ()
{
  has_focus = true;
}

void
SmallMap::on_pointer_leave ()
{
  has_focus = false;
}

/* EOF */
