#ifndef USING_H
#define USING_H


#include "storage/Holders/Holder.h"


namespace storage
{

    class Using : public Holder
    {
    public:

	static Using* create(DeviceGraph& device_graph, const Device* source, const Device* target);

    private:

	Using(DeviceGraph& device_graph, const Device* source, const Device* target);

    };

}

#endif
