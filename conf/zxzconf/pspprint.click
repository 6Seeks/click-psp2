c :: Classifier(12/0600, 12/0601, 12/060200, 12/060201, -);
arpresponder :: MyARPResponder(00.02.02.42.c0.a8.02.02, 02:42:c0:a8:02:02);

FromDevice(eth2)->c;
c[0]->Print("0")->Discard;
c[1]->Print("1")->Discard;
c[2]->Print("2")->arpresponder->Queue(200)->ToDevice(eth2);
c[3]->Print("3")->Discard;
c[4]->Print("4")->Discard;
