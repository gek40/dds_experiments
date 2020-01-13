// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file StdMsgsStringSubscriber.cpp
 *
 */

#include "StdMsgsStringSubscriber.h"
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/Domain.h>
#include <fastrtps/utils/eClock.h>
#include <fastrtps/types/DynamicTypeBuilderFactory.h>
#include <fastrtps/types/DynamicDataFactory.h>
#include <fastrtps/types/DynamicTypeBuilder.h>
#include <fastrtps/types/DynamicTypeBuilderPtr.h>
#include <fastrtps/types/TypeDescriptor.h>
#include <fastrtps/types/MemberDescriptor.h>
#include <fastrtps/types/DynamicType.h>

using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;

StdMsgsStringSubscriber::StdMsgsStringSubscriber()
  : mp_participant(nullptr)
  , mp_subscriber(nullptr)
  , m_DynType(nullptr)
{
}

bool StdMsgsStringSubscriber::init()
{
  ParticipantAttributes PParam;
  PParam.rtps.builtin.domainId = 0;
  PParam.rtps.setName("DynStdMsgsString_sub");
  PParam.rtps.builtin.use_SIMPLE_RTPSParticipantDiscoveryProtocol = true;
  mp_participant = Domain::createParticipant(PParam, (ParticipantListener*)&m_part_list);
  if(mp_participant==nullptr)
    return false;

  //  Create basic types and add members to the struct.
  DynamicTypeBuilder_ptr created_type_string = DynamicTypeBuilderFactory::GetInstance()->CreateStringBuilder();
  DynamicTypeBuilder_ptr struct_type_builder = DynamicTypeBuilderFactory::GetInstance()->CreateStructBuilder();
  struct_type_builder->AddMember(0, "data", created_type_string.get());
  struct_type_builder->SetName("std_msgs__String");
  DynamicType_ptr dynType = struct_type_builder->Build();
  m_DynType.SetDynamicType(dynType);
  m_listener.m_DynHello = DynamicDataFactory::GetInstance()->CreateData(dynType);

  //REGISTER THE TYPE
  Domain::registerDynamicType(mp_participant, &m_DynType);

  //CREATE THE SUBSCRIBER
  SubscriberAttributes Rparam;
  Rparam.topic.topicKind = NO_KEY;
  Rparam.topic.topicDataType = "std_msgs__String";
  Rparam.topic.topicName = "StdMsgsString_Topic";
  // Rparam.qos.m_partition.push_back("StdMsgsString Partition");
  Rparam.topic.topicDiscoveryKind = NO_CHECK; // Do it compatible with other StdMsgsStrings

  mp_subscriber = Domain::createSubscriber(mp_participant,Rparam,(SubscriberListener*)&m_listener);

  if(mp_subscriber == nullptr)
    return false;


  return true;
}

StdMsgsStringSubscriber::~StdMsgsStringSubscriber() {
  // TODO Auto-generated destructor stub
  Domain::removeParticipant(mp_participant);

  DynamicDataFactory::GetInstance()->DeleteData(m_listener.m_DynHello);

  Domain::stopAll();
}

void StdMsgsStringSubscriber::SubListener::onSubscriptionMatched(Subscriber* sub,MatchingInfo& info)
{
  if(info.status == MATCHED_MATCHING)
  {
    n_matched++;
    std::cout << "Subscriber matched , info.remoteEndpointGuid.entityId.value = " << info.remoteEndpointGuid.entityId.value << std::endl;
  }
  else
  {
    n_matched--;
    std::cout << "Subscriber unmatched"<<std::endl;
  }
}

void StdMsgsStringSubscriber::PartListener::onParticipantDiscovery(Participant*, ParticipantDiscoveryInfo&& info)
{
  if(info.status == ParticipantDiscoveryInfo::DISCOVERED_PARTICIPANT)
  {
    std::cout << "Participant " << info.info.m_participantName << " discovered" << std::endl;
  }
  else if(info.status == ParticipantDiscoveryInfo::REMOVED_PARTICIPANT)
  {
    std::cout << "Participant " << info.info.m_participantName << " removed" << std::endl;
  }
  else if(info.status == ParticipantDiscoveryInfo::DROPPED_PARTICIPANT)
  {
    std::cout << "Participant " << info.info.m_participantName << " dropped" << std::endl;
  }
}

void StdMsgsStringSubscriber::PartListener::onPublisherDiscovery(Participant* p, rtps::WriterDiscoveryInfo&& info)
{
  if(strcmp(info.info.topicName().c_str(),"StdMsgsString_Topic")!=0)
    return;
  std::cout << "\n\nonPublisherDiscovery: typeName = " << info.info.typeName() << ", topicName = " << info.info.topicName()
            << ", \n topicDiscoveryKind = "<< info.info.topicDiscoveryKind()
            << ", \n topicKind = " << info.info.topicKind()
            << ", \n info.info.isAlive() = " << info.info.isAlive()
            << ", \n m_durability.kind = " << info.info.m_qos.m_durability.kind
            << ", \n m_deadline.period = " << info.info.m_qos.m_deadline.period
            << ", \n m_latencyBudget.duration = " << info.info.m_qos.m_latencyBudget.duration
            << ", \n m_ownership.kind = " << info.info.m_qos.m_ownership.kind
            << ", \n m_ownershipStrength.value = " << info.info.m_qos.m_ownershipStrength.value
            << ", \n m_liveliness.kind = " << info.info.m_qos.m_liveliness.kind
            << ", \n m_liveliness.lease_duration = " << info.info.m_qos.m_liveliness.lease_duration
            << ", \n m_reliability.kind = " << info.info.m_qos.m_reliability.kind
            << ", \n m_reliability.max_blocking_time = " << info.info.m_qos.m_reliability.max_blocking_time
            << ", \n m_lifespan.duration = " << info.info.m_qos.m_lifespan.duration
            << ", \n m_destinationOrder.kind = " << info.info.m_qos.m_destinationOrder.kind
            << ", \n key().isDefined() = " << info.info.key().isDefined()
            << ", \n m_durabilityService.max_samples = " << info.info.m_qos.m_durabilityService.max_samples
            << ", \n m_durabilityService.max_instances = " << info.info.m_qos.m_durabilityService.max_instances
            << ", \n m_durabilityService.max_samples_per_instance = " << info.info.m_qos.m_durabilityService.max_samples_per_instance
            << ", \n Partitions: ";
  for (int i = 0; i < info.info.m_qos.m_partition.getNames().size(); i++)
  {
    std::cout << " [" << i << "]: " << info.info.m_qos.m_partition.getNames().at(i) << "\n ";
  }
  std::cout << "\n --------------------------------"
            <<  std::endl;
}

void StdMsgsStringSubscriber::SubListener::onNewDataMessage(Subscriber* sub)
{
  std::cout << "onNewDataMessage from " << sub->getAttributes().topic.topicName << " with type " << sub->getAttributes().topic.topicDataType << std::endl;
  if(sub->takeNextData((void*)m_DynHello, &m_info))
  {
    //if(m_info.sampleKind == ALIVE)
    {
      this->n_samples++;
      // Print your structure data here.
      std::string message;
      m_DynHello->GetStringValue(message, 0);

      std::cout << "!!! Message: " << message << " RECEIVED" << std::endl;
    }
  }
}


void StdMsgsStringSubscriber::run()
{
  std::cout << "Subscriber running. Please press enter to stop the Subscriber" << std::endl;
  std::cin.ignore();
}

void StdMsgsStringSubscriber::run(uint32_t number)
{
  std::cout << "Subscriber running until "<< number << "samples have been received"<<std::endl;
  while(number > this->m_listener.n_samples)
    eClock::my_sleep(500);
}
