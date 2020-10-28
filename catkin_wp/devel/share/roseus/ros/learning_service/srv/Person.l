;; Auto-generated. Do not edit!


(when (boundp 'learning_service::Person)
  (if (not (find-package "LEARNING_SERVICE"))
    (make-package "LEARNING_SERVICE"))
  (shadow 'Person (find-package "LEARNING_SERVICE")))
(unless (find-package "LEARNING_SERVICE::PERSON")
  (make-package "LEARNING_SERVICE::PERSON"))
(unless (find-package "LEARNING_SERVICE::PERSONREQUEST")
  (make-package "LEARNING_SERVICE::PERSONREQUEST"))
(unless (find-package "LEARNING_SERVICE::PERSONRESPONSE")
  (make-package "LEARNING_SERVICE::PERSONRESPONSE"))

(in-package "ROS")





(intern "*UNKNOWN*" (find-package "LEARNING_SERVICE::PERSONREQUEST"))
(shadow '*UNKNOWN* (find-package "LEARNING_SERVICE::PERSONREQUEST"))
(defconstant learning_service::PersonRequest::*UNKNOWN* 0)
(intern "*MALE*" (find-package "LEARNING_SERVICE::PERSONREQUEST"))
(shadow '*MALE* (find-package "LEARNING_SERVICE::PERSONREQUEST"))
(defconstant learning_service::PersonRequest::*MALE* 1)
(intern "*FEMALE*" (find-package "LEARNING_SERVICE::PERSONREQUEST"))
(shadow '*FEMALE* (find-package "LEARNING_SERVICE::PERSONREQUEST"))
(defconstant learning_service::PersonRequest::*FEMALE* 2)
(defclass learning_service::PersonRequest
  :super ros::object
  :slots (_name _age _sex ))

(defmethod learning_service::PersonRequest
  (:init
   (&key
    ((:name __name) "")
    ((:age __age) 0)
    ((:sex __sex) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _age (round __age))
   (setq _sex (round __sex))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:sex
   (&optional __sex)
   (if __sex (setq _sex __sex)) _sex)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint8 _age
    1
    ;; uint8 _sex
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _age
       (write-byte _age s)
     ;; uint8 _sex
       (write-byte _sex s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _sex
     (setq _sex (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass learning_service::PersonResponse
  :super ros::object
  :slots (_result ))

(defmethod learning_service::PersonResponse
  (:init
   (&key
    ((:result __result) "")
    )
   (send-super :init)
   (setq _result (string __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; string _result
    4 (length _result)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _result
       (write-long (length _result) s) (princ _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _result
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _result (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass learning_service::Person
  :super ros::object
  :slots ())

(setf (get learning_service::Person :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get learning_service::Person :datatype-) "learning_service/Person")
(setf (get learning_service::Person :request) learning_service::PersonRequest)
(setf (get learning_service::Person :response) learning_service::PersonResponse)

(defmethod learning_service::PersonRequest
  (:response () (instance learning_service::PersonResponse :init)))

(setf (get learning_service::PersonRequest :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get learning_service::PersonRequest :datatype-) "learning_service/PersonRequest")
(setf (get learning_service::PersonRequest :definition-)
      "string name
uint8  age
uint8  sex

uint8 unknown = 0
uint8 male    = 1
uint8 female  = 2

---
string result

")

(setf (get learning_service::PersonResponse :md5sum-) "c198113e7dd9cc5c9fd5f271c8479b39")
(setf (get learning_service::PersonResponse :datatype-) "learning_service/PersonResponse")
(setf (get learning_service::PersonResponse :definition-)
      "string name
uint8  age
uint8  sex

uint8 unknown = 0
uint8 male    = 1
uint8 female  = 2

---
string result

")



(provide :learning_service/Person "c198113e7dd9cc5c9fd5f271c8479b39")


