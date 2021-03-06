//  Pingus - A free Lemmings clone
//  Copyright (C) 2000,2007 Ingo Ruhnke <grumbel@gmx.de>
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

#ifndef HEADER_PINGUS_PINGUS_WORLDMAP_WORLDMAP_SCREEN_HPP
#define HEADER_PINGUS_PINGUS_WORLDMAP_WORLDMAP_SCREEN_HPP

#include "engine/display/sprite.hpp"
#include "engine/gui/gui_manager.hpp"
#include "engine/screen/gui_screen.hpp"

namespace GUI {
class SurfaceButton;
}

class SceneContext;
namespace WorldmapNS {

typedef int NodeId;
class Worldmap;

/** The WorldmapScreen manages the worldmaps and the translation
    between two worldmaps, it also holds the GUI elements that are
    accessible in the Worldmap Screen */
class WorldmapScreen: public GUIScreen {
public:
  WorldmapScreen();
  ~WorldmapScreen();

  void load(const Pathname& filename);  

private:
  WorldmapScreen (const WorldmapScreen&);
  WorldmapScreen& operator= (const WorldmapScreen&);
};

} // namespace WorldmapNS

struct WorldmapScreenLoadPackage {
  WorldmapNS::WorldmapScreen* screen;
  const Pathname& filename;

  WorldmapScreenLoadPackage(WorldmapNS::WorldmapScreen* s, const Pathname& f): screen(s), filename(f) {};
};

#endif

/* EOF */
