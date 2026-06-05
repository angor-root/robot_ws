#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "camera_detection_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__camera_detection_interfaces__srv__DetectPipe_Request() -> *const std::ffi::c_void;
}

#[link(name = "camera_detection_interfaces__rosidl_generator_c")]
extern "C" {
    fn camera_detection_interfaces__srv__DetectPipe_Request__init(msg: *mut DetectPipe_Request) -> bool;
    fn camera_detection_interfaces__srv__DetectPipe_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DetectPipe_Request>, size: usize) -> bool;
    fn camera_detection_interfaces__srv__DetectPipe_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DetectPipe_Request>);
    fn camera_detection_interfaces__srv__DetectPipe_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DetectPipe_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<DetectPipe_Request>) -> bool;
}

// Corresponds to camera_detection_interfaces__srv__DetectPipe_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DetectPipe_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for DetectPipe_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !camera_detection_interfaces__srv__DetectPipe_Request__init(&mut msg as *mut _) {
        panic!("Call to camera_detection_interfaces__srv__DetectPipe_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DetectPipe_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { camera_detection_interfaces__srv__DetectPipe_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { camera_detection_interfaces__srv__DetectPipe_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { camera_detection_interfaces__srv__DetectPipe_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DetectPipe_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DetectPipe_Request where Self: Sized {
  const TYPE_NAME: &'static str = "camera_detection_interfaces/srv/DetectPipe_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__camera_detection_interfaces__srv__DetectPipe_Request() }
  }
}


#[link(name = "camera_detection_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__camera_detection_interfaces__srv__DetectPipe_Response() -> *const std::ffi::c_void;
}

#[link(name = "camera_detection_interfaces__rosidl_generator_c")]
extern "C" {
    fn camera_detection_interfaces__srv__DetectPipe_Response__init(msg: *mut DetectPipe_Response) -> bool;
    fn camera_detection_interfaces__srv__DetectPipe_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DetectPipe_Response>, size: usize) -> bool;
    fn camera_detection_interfaces__srv__DetectPipe_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DetectPipe_Response>);
    fn camera_detection_interfaces__srv__DetectPipe_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DetectPipe_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<DetectPipe_Response>) -> bool;
}

// Corresponds to camera_detection_interfaces__srv__DetectPipe_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    pub message: rosidl_runtime_rs::String,

}



impl Default for DetectPipe_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !camera_detection_interfaces__srv__DetectPipe_Response__init(&mut msg as *mut _) {
        panic!("Call to camera_detection_interfaces__srv__DetectPipe_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DetectPipe_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { camera_detection_interfaces__srv__DetectPipe_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { camera_detection_interfaces__srv__DetectPipe_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { camera_detection_interfaces__srv__DetectPipe_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DetectPipe_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DetectPipe_Response where Self: Sized {
  const TYPE_NAME: &'static str = "camera_detection_interfaces/srv/DetectPipe_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__camera_detection_interfaces__srv__DetectPipe_Response() }
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


