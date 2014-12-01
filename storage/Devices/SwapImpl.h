#ifndef SWAP_IMPL_H
#define SWAP_IMPL_H


#include "storage/Devices/Swap.h"
#include "storage/Devices/FilesystemImpl.h"


namespace storage
{

    using namespace std;


    class Swap::Impl : public Filesystem::Impl
    {
    public:

	Impl(DeviceGraph& device_graph)
	    : Filesystem::Impl(device_graph) {}

	Impl(DeviceGraph& device_graph, const Impl& impl)
	    : Filesystem::Impl(device_graph, impl) {}

	virtual const char* getClassName() const override { return "Swap"; }

	virtual Impl* clone(DeviceGraph& device_graph) const override { return new Impl(device_graph, *this); }

	virtual void save(xmlNode* node) const override;

	virtual void add_create_actions(ActionGraph& action_graph) const override;

    };

}

#endif
