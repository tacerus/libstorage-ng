#!/usr/bin/python

# requirements: disk /dev/sdb with msdos partition table and partition /dev/sdb1


from storage import *
from storageitu import *


environment = Environment(False)

storage = Storage(environment)
storage.probe()

staging = storage.get_staging()

print staging

partition = Partition.find_by_name(staging, "/dev/sdb1")
partition.set_id(ID_LINUX)

vfat = partition.create_blk_filesystem(FsType_VFAT)
vfat.set_label("TEST")

mount_point = vfat.create_mount_point("/test")

print staging

commit(storage)

