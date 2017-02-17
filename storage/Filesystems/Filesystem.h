/*
 * Copyright (c) [2014-2015] Novell, Inc.
 * Copyright (c) 2016 SUSE LLC
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
 * with this program; if not, contact Novell, Inc.
 *
 * To contact Novell about this file by physical or electronic mail, you may
 * find current contact information at www.novell.com.
 */


#ifndef STORAGE_FILESYSTEM_H
#define STORAGE_FILESYSTEM_H


#include <vector>
#include <list>

#include "storage/Devices/Device.h"


namespace storage
{

    class BlkDevice;
    class ContentInfo;


    enum class FsType {
	UNKNOWN, REISERFS, EXT2, EXT3, EXT4, BTRFS, VFAT, XFS, JFS, HFS, NTFS,
	SWAP, HFSPLUS, NFS, NFS4, TMPFS, ISO9660, UDF, NILFS2
    };


    //! The key by which the mount program identifies a filesystem
    enum class MountByType {
	DEVICE, UUID, LABEL, ID, PATH
    };


    std::string get_mount_by_name(MountByType mount_by_type);


    // abstract class

    class Filesystem : public Device
    {
    public:

	static std::vector<Filesystem*> get_all(Devicegraph* devicegraph);
	static std::vector<const Filesystem*> get_all(const Devicegraph* devicegraph);

	FsType get_type() const;

	virtual bool supports_label() const = 0;
	virtual unsigned int max_labelsize() const = 0;

	const std::string& get_label() const;
	void set_label(const std::string& label);

	virtual bool supports_uuid() const = 0;

	const std::string& get_uuid() const;
	void set_uuid(const std::string& uuid);

	const std::vector<std::string>& get_mountpoints() const;
	void set_mountpoints(const std::vector<std::string>& mountpoints);
	void add_mountpoint(const std::string& mountpoint);

	MountByType get_mount_by() const;
	void set_mount_by(MountByType mount_by);

	const std::list<std::string>& get_fstab_options() const;
	void set_fstab_options(const std::list<std::string>& fstab_options);

	const std::string& get_mkfs_options() const;
	void set_mkfs_options(const std::string& mkfs_options);

	const std::string& get_tune_options() const;
	void set_tune_options(const std::string& tune_options);

	/**
	 * Set the ResizeInfo. Only use for testsuites.
	 */
	void set_resize_info(const ResizeInfo& resize_info);

	ContentInfo detect_content_info() const;

	/**
	 * Set the ResizeInfo. Only use for testsuites.
	 */
	void set_content_info(const ContentInfo& content_info);

	static std::vector<Filesystem*> find_by_label(const Devicegraph* devicegraph,
						      const std::string& label);

	static std::vector<Filesystem*> find_by_mountpoint(const Devicegraph* devicegraph,
							   const std::string& mountpoint);

	// TODO class BlkFilesystem for not nfs, tmpfs?
	std::vector<const BlkDevice*> get_blk_devices() const;

    public:

	class Impl;

	Impl& get_impl();
	const Impl& get_impl() const;

    protected:

	Filesystem(Impl* impl);

    };


    bool is_filesystem(const Device* device);

    Filesystem* to_filesystem(Device* device);
    const Filesystem* to_filesystem(const Device* device);

}

#endif
