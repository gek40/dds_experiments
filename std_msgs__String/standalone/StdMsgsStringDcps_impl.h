#ifndef STDMSGSSTRINGDCPS_IMPL_H_
#define STDMSGSSTRINGDCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_StdMsgsString.h"
#include "TypeSupportMetaHolder.h"
#include "TypeSupport.h"
#include "FooDataWriter_impl.h"
#include "FooDataReader_impl.h"
#include "FooDataReaderView_impl.h"


class  std_msgs__StringTypeSupportMetaHolder : public ::DDS::OpenSplice::TypeSupportMetaHolder
{
public:
    std_msgs__StringTypeSupportMetaHolder ();
    virtual ~std_msgs__StringTypeSupportMetaHolder ();

private:
    ::DDS::OpenSplice::TypeSupportMetaHolder * clone();

    ::DDS::OpenSplice::DataWriter * create_datawriter ();

    ::DDS::OpenSplice::DataReader * create_datareader ();

    ::DDS::OpenSplice::DataReaderView * create_view ();
};

class  std_msgs__StringTypeSupport : public virtual std_msgs__StringTypeSupportInterface,
                                                   public ::DDS::OpenSplice::TypeSupport
{
public:
    std_msgs__StringTypeSupport ();

    virtual ~std_msgs__StringTypeSupport ();

private:
    std_msgs__StringTypeSupport (const std_msgs__StringTypeSupport &);

    std_msgs__StringTypeSupport & operator= (const std_msgs__StringTypeSupport &);
};

typedef std_msgs__StringTypeSupportInterface_var std_msgs__StringTypeSupport_var;
typedef std_msgs__StringTypeSupportInterface_ptr std_msgs__StringTypeSupport_ptr;

class  std_msgs__StringDataWriter_impl : public virtual std_msgs__StringDataWriter,
                                                       public ::DDS::OpenSplice::FooDataWriter_impl
{
    friend class DDS::OpenSplice::Publisher;
    friend class std_msgs__StringTypeSupportMetaHolder;

public:
    virtual ::DDS::InstanceHandle_t register_instance (
        const std_msgs__String & instance_data) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
        const std_msgs__String & instance_data,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance (
        const std_msgs__String & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
        const std_msgs__String & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write (
        const std_msgs__String & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write_w_timestamp (
        const std_msgs__String & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose (
        const std_msgs__String & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose_w_timestamp (
        const std_msgs__String & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose (
        const std_msgs__String & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose_w_timestamp (
        const std_msgs__String & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value (
        std_msgs__String & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance (
        const std_msgs__String & instance_data) THROW_ORB_EXCEPTIONS;

protected:
    std_msgs__StringDataWriter_impl ();

    virtual ~std_msgs__StringDataWriter_impl ();

    virtual DDS::ReturnCode_t init (
                    DDS::OpenSplice::Publisher *publisher,
                    DDS::OpenSplice::DomainParticipant *participant,
                    const DDS::DataWriterQos &qos,
                    DDS::OpenSplice::Topic *a_topic,
                    const char *name,
                    DDS::OpenSplice::cxxCopyIn copyIn,
                    DDS::OpenSplice::cxxCopyOut copyOut,
                    u_writerCopy writerCopy,
                    void *cdrMarshaler);

private:
    std_msgs__StringDataWriter_impl (const std_msgs__StringDataWriter_impl &);

    std_msgs__StringDataWriter_impl & operator= (const std_msgs__StringDataWriter_impl &);
};

class  std_msgs__StringDataReader_impl : public virtual std_msgs__StringDataReader,
                                                       public ::DDS::OpenSplice::FooDataReader_impl
{
    friend class DDS::OpenSplice::Subscriber;
    friend class std_msgs__StringTypeSupportMetaHolder;
    friend class std_msgs__StringDataReaderView_impl;

public:
    virtual ::DDS::ReturnCode_t read (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_w_condition (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_w_condition (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample (
        std_msgs__String & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample (
        std_msgs__String & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_instance (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_instance (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value (
        std_msgs__String & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance (
        const std_msgs__String & instance) THROW_ORB_EXCEPTIONS;

protected:
    std_msgs__StringDataReader_impl ();

    virtual ~std_msgs__StringDataReader_impl ();

    DDS::ReturnCode_t init (
            DDS::OpenSplice::Subscriber *subscriber,
            const DDS::DataReaderQos &qos,
            DDS::OpenSplice::TopicDescription *a_topic,
            const char *name,
            DDS::OpenSplice::cxxCopyIn copyIn,
            DDS::OpenSplice::cxxCopyOut copyOut,
            DDS::OpenSplice::cxxReaderCopy readerCopy,
            void *cdrMarshaler);

    static void* dataSeqAlloc (
        void * data_values,
        DDS::ULong len);

    static void dataSeqLength (
        void * data_values,
        DDS::ULong len);

    static void * dataSeqGetBuffer (
        void * data_values,
        DDS::ULong index);

    static void dataSeqCopyOut (
        const void * from,
        void * received_data);
    static void copyDataOut(const void *from, void *to);

private:
    std_msgs__StringDataReader_impl (const std_msgs__StringDataReader_impl &);
    std_msgs__StringDataReader_impl & operator= (const std_msgs__StringDataReader_impl &);

    static ::DDS::ReturnCode_t check_preconditions (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples);
};

class  std_msgs__StringDataReaderView_impl : public virtual std_msgs__StringDataReaderView,
                                                           public ::DDS::OpenSplice::FooDataReaderView_impl
{
    friend class DDS::OpenSplice::DataReader;
    friend class std_msgs__StringTypeSupportMetaHolder;

public:
    virtual ::DDS::ReturnCode_t read (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_w_condition (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_w_condition (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample (
        std_msgs__String & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample (
        std_msgs__String & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_instance (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_instance (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan (
        std_msgs__StringSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value (
        std_msgs__String & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance (
        const std_msgs__String & instance) THROW_ORB_EXCEPTIONS;

protected:
    std_msgs__StringDataReaderView_impl ();

    virtual ~std_msgs__StringDataReaderView_impl ();

    virtual DDS::ReturnCode_t init (
        DDS::OpenSplice::DataReader *reader,
        const char *name,
        const DDS::DataReaderViewQos &qos,
        DDS::OpenSplice::cxxCopyIn copyIn,
        DDS::OpenSplice::cxxCopyOut copyOut);

private:
    std_msgs__StringDataReaderView_impl (const std_msgs__StringDataReaderView_impl &);

    std_msgs__StringDataReaderView_impl & operator= (const std_msgs__StringDataReaderView_impl &);
};

#undef OS_API
#endif
