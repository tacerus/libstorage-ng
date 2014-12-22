#ifndef PARTITION_TABLE_H
#define PARTITION_TABLE_H


#include <vector>

#include "storage/Devices/Device.h"
#include "storage/Devices/Partition.h"


namespace storage
{
    class Disk;


    enum class PtType {
	PT_UNKNOWN, PT_LOOP, MSDOS, GPT, DASD, MAC
    };


    // abstract class

    class PartitionTable : public Device
    {
    public:

	Partition* create_partition(const std::string& name);
	Partition* create_partition(unsigned int number);

	void delete_partition(const std::string& name);

	std::vector<const Partition*> get_partitions() const;

	Partition* get_partition(const std::string& name);

	const Disk* get_disk() const;

    public:

	class Impl;

	Impl& get_impl();
	const Impl& get_impl() const;

    protected:

	PartitionTable(Impl* impl);

	void print(std::ostream& out) const override = 0;

    };


    inline const PartitionTable*
    to_partition_table(const Device* device)
    {
	return dynamic_cast<const PartitionTable*>(device);
    }

}

#endif
