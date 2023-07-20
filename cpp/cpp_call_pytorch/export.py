import torch
from torchvision.models import resnet50

net = resnet50(pretrained=True)
# net = net.cuda()
net.eval()
for key, value in net.named_parameters():
	print(key)

# trace
x = torch.ones(1, 3, 224, 224)
# x = x.cuda()
traced_module = torch.jit.trace(net, x)
traced_module.save("resnet50_trace.pt")

# script
scripted_module = torch.jit.script(net)
scripted_module.save("resnet50_script.pt")
