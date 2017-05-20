/*
 * Copyright (c) 2017 SUSE LLC
 *
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, contact SUSE LLC.
 *
 * To contact SUSE LLC about this file by physical or electronic mail, you may
 * find current contact information at www.suse.com.
 */


#ifndef STORAGE_COMPOUND_ACTION_H
#define STORAGE_COMPOUND_ACTION_H


#include <memory>
#include <string>
#include <boost/noncopyable.hpp>


namespace storage
{

    namespace Action
    {
	class Base;
    }

    class Actiongraph;
    class Device;

    class CompoundAction : private boost::noncopyable
    {

    public:

	CompoundAction(const Actiongraph* actiongraph);
	~CompoundAction();

	const Device* get_target_device() const;

	std::string sentence() const;
	
	bool is_delete() const;

    public:

	class Generator;
	class Formatter;

	class Impl;

	Impl& get_impl() { return *impl; }
	const Impl& get_impl() const { return *impl; }

    private:
    
	const std::unique_ptr<Impl> impl;
    
    };

}

#endif

