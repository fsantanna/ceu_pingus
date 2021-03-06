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

#include "pingus/server.hpp"

#include <fstream>
#include <time.h>

#include "util/log.hpp"
#include "util/sexpr_file_writer.hpp"
#include "util/system.hpp"

#include "ceuvars.h"

static std::string get_date_string ()
{
  char buffer[32];
  time_t curtime;
  struct tm *loctime;
  curtime = time (NULL);
  loctime = localtime(&curtime);
  strftime(buffer, 32, "%Y%m%d-%H%M%S", loctime);

  return std::string(buffer);
}

std::unique_ptr<std::ostream> get_demostream(const PingusLevel& plf)
{
  std::string flat_levelname = plf.get_resname();

  // 'Flatten' the levelname so that we don't need directories
  for (std::string::iterator i = flat_levelname.begin(); i != flat_levelname.end(); ++i)
    if (*i == '/')
      *i = '_';

  std::string filename = System::get_userdir() + "demos/" + flat_levelname + "-" + get_date_string() + ".pingus-demo";

  std::unique_ptr<std::ofstream> out(new std::ofstream(filename.c_str()));
  
  if (!(*out.get()))
  {
    log_error("DemoRecorder: Error: Couldn't write DemoFile '%1%', demo recording will be disabled", filename);
    return std::unique_ptr<std::ostream>();
  }
  else
  {
    log_info("DemoRecorder: Writing demo to: %1%", filename);

    // Write file header
    SExprFileWriter writer(*out);
    writer.begin_section("level");
    writer.write_string("name", plf.get_resname());
    writer.write_string("checksum", plf.get_checksum());
    writer.end_section();
    *out << std::endl;
    return std::unique_ptr<std::ostream>(out.release());
  }
}

Server::Server(const PingusLevel& arg_plf) :
  plf(arg_plf),  
  action_holder(plf),
  demostream()
{}

ActionHolder*
Server::get_action_holder ()
{
  return &action_holder;
}

/* EOF */
