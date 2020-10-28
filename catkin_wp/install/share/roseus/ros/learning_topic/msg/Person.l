;; Auto-generated. Do not edit!


(when (boundp 'learning_topic::Person)
  (if (not (find-package "LEARNING_TOPIC"))
    (make-package "LEARNING_TOPIC"))
  (shadow 'Person (find-package "LEARNING_TOPIC")))
(unless (find-package "LEARNING_TOPIC::PERSON")
  (make-package "LEARNING_TOPIC::PERSON"))

(in-package "ROS")
;;//! \htmlinclude Person.msg.html


(intern "*UNKNOWN*" (find-package "LEARNING_TOPIC::PERSON"))
(shadow '*UNKNOWN* (find-package "LEARNING_TOPIC::PERSON"))
(defconstant learning_topic::Person::*UNKNOWN* 0)
(intern "*MALE*" (find-package "LEARNING_TOPIC::PERSON"))
(shadow '*MALE* (find-package "LEARNING_TOPIC::PERSON"))
(defconstant learning_topic::Person::*MALE* 1)
(intern "*FEMALE*" (find-package "LEARNING_TOPIC::PERSON"))
(shadow '*FEMALE* (find-package "LEARNING_TOPIC::PERSON"))
(defconstant learning_topic::Person::*FEMALE* 2)
(defclass learning_topic::Person
  :super ros::object
  :slots (_name _age _sex ))

(defmethod learning_topic::Person
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

(setf (get learning_topic::Person :md5sum-) "b3f7ec37d11629ec3010e27635cf22a9")
(setf (get learning_topic::Person :datatype-) "learning_topic/Person")
(setf (get learning_topic::Person :definition-)
      "string name
uint8  age
uint8  sex

uint8 unknown = 0
uint8 male    = 1
uint8 female  = 2
")



(provide :learning_topic/Person "b3f7ec37d11629ec3010e27635cf22a9")


