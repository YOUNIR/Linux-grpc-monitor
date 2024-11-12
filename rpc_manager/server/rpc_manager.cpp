#include "rpc_manager.h"

#include <iostream>

namespace monitor {
GrpcManagerImpl::GrpcManagerImpl() {}

GrpcManagerImpl::~GrpcManagerImpl() {}

::grpc::Status GrpcManagerImpl::SetMonitorInfo(
    ::grpc::ServerContext* context,
    const ::monitor::proto::MonitorInfo* request,
    ::google::protobuf::Empty* response) {
  monitor_infos_.Clear();
  monitor_infos_ = *request;
  std::cout << "jinru" << request->soft_irq_size() << std::endl;
  //     std::cout << request->soft_irq(i).cpu() << " " <<
  //     request->soft_irq(i).hi()
  //               << " " << request->soft_irq(i).timer() << " "
  //               << request->soft_irq(i).net_tx() << " "
  //               << request->soft_irq(i).net_rx() << " "
  //               << request->soft_irq(i).block() << " "
  //               << request->soft_irq(i).irq_poll() << std::endl;
  //   }
  return grpc::Status::OK;
}

::grpc::Status GrpcManagerImpl::GetMonitorInfo(
    ::grpc::ServerContext* context, const ::google::protobuf::Empty* request,
    ::monitor::proto::MonitorInfo* response) {
  *response = monitor_infos_;
  return grpc::Status::OK;
}

}  // namespace monitor
