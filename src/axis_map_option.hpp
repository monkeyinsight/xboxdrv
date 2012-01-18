/*
**  Xbox360 USB Gamepad Userspace Driver
**  Copyright (C) 2011 Ingo Ruhnke <grumbel@gmx.de>
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HEADER_XBOXDRV_AXIS_MAP_OPTION_HPP
#define HEADER_XBOXDRV_AXIS_MAP_OPTION_HPP

#include <string>
#include <vector>

class AxisMapOption
{
private:
  std::string m_axis;
  std::vector<std::string> m_buttons;
  std::vector<std::string> m_filter;
  std::string m_event;
  std::string m_directory;
  
public:
  AxisMapOption(const std::string& axis,
                const std::string& event) :
    m_axis(axis),
    m_buttons(),
    m_filter(),
    m_event(event),
    m_directory() // BROKEN: needs get_directory_context() or something more clever
  {}

  void add_filter(const std::string& filter)
  {
    m_filter.push_back(filter);
  }

  const std::string& get_axis() const { return m_axis; }
  const std::vector<std::string>& get_filter() const { return m_filter; }
  const std::string& get_event() const { return m_event; }
  const std::string& get_directory() const { return m_directory; }
};

typedef std::vector<AxisMapOption> AxisMapOptions;

#endif

/* EOF */
