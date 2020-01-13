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
 * @file StdMsgsStringPublisher.cpp
 *
 */

#include "StdMsgsStringPublisher.h"
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/Domain.h>
#include <fastrtps/utils/eClock.h>
#include <fastrtps/types/DynamicTypeBuilderFactory.h>
#include <fastrtps/types/DynamicDataFactory.h>
#include <fastrtps/types/DynamicTypeBuilder.h>
#include <fastrtps/types/DynamicTypeBuilderPtr.h>
#include <fastrtps/types/TypeDescriptor.h>
#include <fastrtps/types/MemberDescriptor.h>
#include <fastrtps/types/DynamicType.h>

#include <thread>

using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;

StdMsgsStringPublisher::StdMsgsStringPublisher()
  : mp_participant(nullptr)
  , mp_publisher(nullptr)
  , m_DynType(nullptr)
{
}

bool StdMsgsStringPublisher::init()
{
  // Create basic builders
  DynamicTypeBuilder_ptr struct_type_builder(DynamicTypeBuilderFactory::GetInstance()->CreateStructBuilder());

  // Add members to the struct.
  struct_type_builder->AddMember(0, "data", DynamicTypeBuilderFactory::GetInstance()->CreateStringType());
  struct_type_builder->SetName("std_msgs__String");

  DynamicType_ptr dynType = struct_type_builder->Build();
  m_DynType.SetDynamicType(dynType);
  m_DynStdMsgsString = DynamicDataFactory::GetInstance()->CreateData(dynType);
  m_DynStdMsgsString->SetStringValue("String from Fast-RTPS", 0);


  ParticipantAttributes PParam;
  PParam.rtps.builtin.domainId = 0;
  PParam.rtps.setName("Dynm_StdMsgsString_pub");
  mp_participant = Domain::createParticipant(PParam, (ParticipantListener*)&m_part_list);

  if(mp_participant==nullptr)
    return false;

  //REGISTER THE TYPE
  Domain::registerDynamicType(mp_participant, &m_DynType);

  //CREATE THE PUBLISHER
  PublisherAttributes Wparam;
  Wparam.topic.topicKind = NO_KEY;
  Wparam.topic.topicDataType = "std_msgs__String";
  Wparam.topic.topicName = "StdMsgsString_Topic";
  // Wparam.qos.m_partition.push_back("StdMsgsString Partition");
  Wparam.topic.topicDiscoveryKind = NO_CHECK;  // Do it compatible with other StdMsgsStrings
  Wparam.qos.m_reliability.kind = RELIABLE_RELIABILITY_QOS;
  Wparam.qos.m_durability.kind = TRANSIENT_LOCAL_DURABILITY_QOS;
  mp_publisher = Domain::createPublisher(mp_participant,Wparam,(PublisherListener*)&m_listener);
  if(mp_publisher == nullptr)
    return false;

  return true;

}

StdMsgsStringPublisher::~StdMsgsStringPublisher()
{
  Domain::removeParticipant(mp_participant);

  DynamicDataFactory::GetInstance()->DeleteData(m_DynStdMsgsString);

  Domain::stopAll();
}

void StdMsgsStringPublisher::PubListener::onPublicationMatched(Publisher* /*pub*/,MatchingInfo& info)
{
  if(info.status == MATCHED_MATCHING)
  {
    n_matched++;
    firstConnected = true;
    std::cout << "Publisher matched"<<std::endl;
  }
  else
  {
    n_matched--;
    std::cout << "Publisher unmatched"<<std::endl;
  }
}

void StdMsgsStringPublisher::PartListener::onParticipantDiscovery(Participant*, ParticipantDiscoveryInfo&& info)
{
  if(info.status == ParticipantDiscoveryInfo::DISCOVERED_PARTICIPANT)
  {
    std::cout << "Participant " << info.info.m_participantName << " discovered" << std::endl;
  }
  else if (info.status == ParticipantDiscoveryInfo::REMOVED_PARTICIPANT)
  {
    std::cout << "Participant " << info.info.m_participantName << " removed" << std::endl;
  }
  else if (info.status == ParticipantDiscoveryInfo::DROPPED_PARTICIPANT)
  {
    std::cout << "Participant " << info.info.m_participantName << " dropped" << std::endl;
  }
}

void StdMsgsStringPublisher::runThread(uint32_t samples, uint32_t sleep)
{
  uint32_t i = 0;

  while(!stop && (i < samples || samples == 0))
  {
    if(publish(samples != 0))
    {
      std::string message;
      m_DynStdMsgsString->GetStringValue(message, 0);

      std::cout << "Data: " << message << " SENT" << std::endl;
      ++i;
    }
    eClock::my_sleep(sleep);
  }
}

void StdMsgsStringPublisher::run(uint32_t samples, uint32_t sleep)
{
  stop = false;
  std::thread thread(&StdMsgsStringPublisher::runThread, this, samples, sleep);
  if (samples == 0)
  {
    std::cout << "Publisher running. Please press enter to stop the Publisher at any time." << std::endl;
    std::cin.ignore();
    stop = true;
  }
  else
  {
    std::cout << "Publisher running " << samples << " samples." << std::endl;
  }
  thread.join();
}

bool StdMsgsStringPublisher::publish(bool waitForListener)
{
  if(m_listener.firstConnected || !waitForListener || m_listener.n_matched>0)
  {
    //int32_t index;
    //m_DynHello->GetInt32Value(index, 0);
    //m_DynHello->SetInt32Value(index+1, 0);
    mp_publisher->write((void*)m_DynStdMsgsString);
    return true;
  }
  return false;
}
