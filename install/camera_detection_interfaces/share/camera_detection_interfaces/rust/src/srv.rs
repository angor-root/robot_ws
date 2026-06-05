#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to camera_detection_interfaces__srv__DetectPipe_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DetectPipe_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for DetectPipe_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::DetectPipe_Request::default())
  }
}

impl rosidl_runtime_rs::Message for DetectPipe_Request {
  type RmwMsg = super::srv::rmw::DetectPipe_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to camera_detection_interfaces__srv__DetectPipe_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DetectPipe_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub found: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub angle: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub num_pipes: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for DetectPipe_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::DetectPipe_Response::default())
  }
}

impl rosidl_runtime_rs::Message for DetectPipe_Response {
  type RmwMsg = super::srv::rmw::DetectPipe_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        found: msg.found,
        angle: msg.angle,
        confidence: msg.confidence,
        num_pipes: msg.num_pipes,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      found: msg.found,
      angle: msg.angle,
      confidence: msg.confidence,
      num_pipes: msg.num_pipes,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      found: msg.found,
      angle: msg.angle,
      confidence: msg.confidence,
      num_pipes: msg.num_pipes,
      message: msg.message.to_string(),
    }
  }
}






#[link(name = "camera_detection_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__camera_detection_interfaces__srv__DetectPipe() -> *const std::ffi::c_void;
}

// Corresponds to camera_detection_interfaces__srv__DetectPipe
#[allow(missing_docs, non_camel_case_types)]
pub struct DetectPipe;

impl rosidl_runtime_rs::Service for DetectPipe {
    type Request = DetectPipe_Request;
    type Response = DetectPipe_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__camera_detection_interfaces__srv__DetectPipe() }
    }
}


