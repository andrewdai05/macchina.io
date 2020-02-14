//
// TimeServiceEventSubscriber.cpp
//
// Package: Generated
// Module:  TimeServiceEventSubscriber
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2006-2016, Applied Informatics Software Engineering GmbH.
//


#include "TimeServiceEventSubscriber.h"
#include "Poco/Delegate.h"
#include "Poco/RemotingNG/Deserializer.h"
#include "Poco/RemotingNG/MethodHandler.h"
#include "Poco/RemotingNG/Serializer.h"
#include "Poco/RemotingNG/ServerTransport.h"
#include "Poco/RemotingNG/TypeDeserializer.h"
#include "Poco/RemotingNG/TypeSerializer.h"
#include "Poco/SharedPtr.h"


namespace Services {


class TimeServiceEvent__wakeUpMethodHandler: public Poco::RemotingNG::MethodHandler
{
public:
	TimeServiceEvent__wakeUpMethodHandler(TimeServiceProxy* pProxy)
	{
		_pProxy = pProxy;
	}

	void invoke(Poco::RemotingNG::ServerTransport& remoting__trans, Poco::RemotingNG::Deserializer& remoting__deser, Poco::RemotingNG::RemoteObject::Ptr remoting__pRemoteObject)
	{
		remoting__staticInitBegin(REMOTING__NAMES);
		static const std::string REMOTING__NAMES[] = {"wakeUp","data"};
		remoting__staticInitEnd(REMOTING__NAMES);
		std::string data;
		remoting__deser.deserializeMessageBegin(REMOTING__NAMES[0], Poco::RemotingNG::SerializerBase::MESSAGE_EVENT);
		Poco::RemotingNG::TypeDeserializer<std::string >::deserialize(REMOTING__NAMES[1], true, remoting__deser, data);
		remoting__deser.deserializeMessageEnd(REMOTING__NAMES[0], Poco::RemotingNG::SerializerBase::MESSAGE_EVENT);
		try
		{
			_pProxy->wakeUp(0, data);
		}
		catch (...)
		{
		}
	}

private:
	TimeServiceProxy* _pProxy;
};


TimeServiceEventSubscriber::TimeServiceEventSubscriber(const std::string& uri, TimeServiceProxy* pProxy):
	Poco::RemotingNG::EventSubscriber(uri)

{
	addMethodHandler("wakeUp", new Services::TimeServiceEvent__wakeUpMethodHandler(pProxy));
}


TimeServiceEventSubscriber::~TimeServiceEventSubscriber()
{
}


void TimeServiceEventSubscriber::event__wakeUp(const std::string& data)
{
}


const std::string TimeServiceEventSubscriber::DEFAULT_NS("");
} // namespace Services

