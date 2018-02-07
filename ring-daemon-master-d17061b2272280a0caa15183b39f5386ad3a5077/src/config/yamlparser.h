/*
 *  Copyright (C) 2004-2017 Savoir-faire Linux Inc.
 *
 *  Author: Alexandre Savard <alexandre.savard@savoirfairelinux.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.
 */

#pragma once

#include <yaml-cpp/yaml.h>

namespace ring { namespace yaml_utils {

// set T to the value stored at key, or leaves T unchanged
// if no value is stored.
template <typename T>
void parseValue(const YAML::Node &node, const char *key, T &value)
{
    value = node[key].as<T>(value);
}

void parsePath(const YAML::Node &node, const char *key, std::string& path, const std::string& base);

std::vector<std::map<std::string, std::string>>
parseVectorMap(const YAML::Node &node, const std::initializer_list<std::string> &keys);

}} // namespace ring::yaml_utils
