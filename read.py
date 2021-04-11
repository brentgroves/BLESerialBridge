import bluepy.btle as btle

class ReadDelegate(btle.DefaultDelegate):
    def handleNotification(self, cHandle, data):
        print(data.decode("utf-8"))

p = btle.Peripheral("64:69:4e:80:b7:8a")
p.withDelegate(ReadDelegate())

while True:
    while p.waitForNotifications(1):
        pass

p.disconnect()