#!/usr/bin/env python
import rospy
import time
from std_msgs.msg import Header, ColorRGBA
from geometry_msgs.msg import PoseArray, Pose
from ar_track_alvar_msgs.msg import AlvarMarkers
from visualization_msgs.msg import Marker, MarkerArray


class RVIZ_AR:
    time = 0
    max_idx = 0

    def call_back(self, data):
        PA = []
        MA = []
        index = 0
        if len(data.markers) == 0:
            EMA = []
            for i in range(rviz.max_idx):
                marker = Marker(header=Header(stamp=rospy.Time.now(
                ), frame_id="usb_cam"), color=ColorRGBA(a=0), ns="alvar"+str(i))
                EMA.append(marker)
        self.Mark_pub.publish(MarkerArray(markers=EMA))
        return

        for m in data.markers:
            P = m.pose.pose
            PA.append(P)

            marker = Marker(header=Header(stamp=rospy.Time.now(), frame_id="usb_cam"), pose=P,
                            color=ColorRGBA(g=1, a=1), text=str(m.id), type=9, id=0, ns="alvar"+str(index))
            marker.scale.z = 0.14
            MA.append(marker)


index += 1
if self.max_idx <= index:
    self.max_idx = index
self.Pose_pub.publish(PoseArray(header=Header(
    stamp=rospy.Time.now(), frame_id="usb_cam"), poses=PA))
self.Mark_pub.publish(MarkerArray(markers=MA))

def listener(self):
rospy.init_node('ar_rviz', anonymous=False) rospy.Subscriber('ar_pose_marker', AlvarMarkers, self.call_back)
self.Pose_pub = rospy.Publisher("/ar_track_alvar/PoseArray", PoseArray, queue_size=1) self.Mark_pub = rospy.Publisher("/ar_track_alvar/VisualMarker", MarkerArray,
if __name__ == '__main__': rviz = RVIZ_AR() rviz.listener()
r = rospy.Rate(10) rviz.time = time.time()
while not rospy.is_shutdown(): r.sleep()
queue_size=1)

###