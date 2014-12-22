#ifndef SUBDEVICE_H
#define SUBDEVICE_H


#include "storage/Holders/Holder.h"


namespace storage
{

    class Subdevice : public Holder
    {
    public:

	static Subdevice* create(Devicegraph* devicegraph, const Device* source, const Device* target);
	static Subdevice* load(Devicegraph* devicegraph, const xmlNode* node);

	virtual const char* get_classname() const override { return "Subdevice"; }

	virtual Subdevice* clone() const override;

    public:

	class Impl;

	Impl& get_impl();
	const Impl& get_impl() const;

    protected:

	Subdevice(Impl* impl);

	void print(std::ostream& out) const override;

    };


    inline Subdevice*
    to_subdevice(Holder* device)
    {
	return dynamic_cast<Subdevice*>(device);
    }


    inline const Subdevice*
    to_subdevice(const Holder* device)
    {
	return dynamic_cast<const Subdevice*>(device);
    }

}

#endif
