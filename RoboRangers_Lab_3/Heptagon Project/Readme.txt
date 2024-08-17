Link to Video:
https://drive.google.com/file/d/1YBTqUz5Mwa3xoAHo0sO0QlYI07Ni0tnP/view?usp=sharing


General Strategy and Tuning: 

We have set a threshold for detecting white line for the middle sensor as 200,
satisfying which we use PID control to follow the white line, making all
calculations of error and derivative w.r.t the middle sensor. We have  set this
relatively low value of threshold to keep our calculations w.r.t the middle
sensor and follow the line cleanly.

We have kept base motor values of 20 and use PID values to adjust them. For
calculating the proportional term of the PID, we use error definition of 
(1.5*extreme sensors differnce)+(central left and central right sensors
difference). We have set these weights after experimenting with different
values. Derivative term is calcuated as usual and Integral term is ignored. 
We have set values of Kp and Kd as 1/10 and 1/120 respectively. These values
again have been set after very careful calibration and experimentation. Keeping
bigger values made execution of normal turns difficult, while smaller values
 were ineffective for sharp turns. Finally, we have kept base motor values
a bit low and don't let them exceed 40 at any stage, otherwise it becomes
difficult to deal with successive sharp turns at small distance gaps.
Otherwise, our robot performs well at higher speeds as well.Also, we had kept
a all white sensor reading as stopping criteria, but that made it difficult to
start behind the white line, but works perfectly if we start a bit ahead of the
starting point.     
