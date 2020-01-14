
rt :: LookupRoute(0.1,1, 
                  0.2,2);
rl :: LookupLabelTable(10,2,20,
                       20,1,10);

c0 :: Classifier(12/0600, 12/0601,  12/060200, 12/060201,  -);
c1 :: Classifier(12/0600, 12/0601, 12/060200, 12/060201,  -);


arpquerier0 :: MyARPQuerier(00.01.02.42.c0.a8.01.03,02:42:c0:a8:01:03);
arpquerier1 :: MyARPQuerier(00.02.02.42.c0.a8.02.03,02:42:c0:a8:02:03);

arpresponder0 :: MyARPResponder(00.01.02.42.c0.a8.01.03,02:42:c0:a8:01:03);
arpresponder1 :: MyARPResponder(00.02.02.42.c0.a8.02.03,02:42:c0:a8:02:03);

out0 :: PQSchedQueue(5)->todevice0 :: ToDevice(eth1);
out1 :: PQSchedQueue(5)->todevice1 :: ToDevice(eth2);

FromDevice(eth1) -> c0;
FromDevice(eth2) -> c1;

c0[0]->rt;
c0[1]->rl;
c0[2]->arpresponder0->[1]out0;
c0[3]->[1]arpquerier0;
c0[4]->Discard;
c1[0]->rt;
c1[1]->rl;
c1[2]->arpresponder1->[1]out1;
c1[3]->[1]arpquerier1;
c1[4]->Discard;

rt[0]->Discard;
rt[1]->MyCheckHeader()->ABCPrint()->[0]arpquerier0;
rt[2]->MyCheckHeader()->ABCPrint()->[0]arpquerier1;
rl[0]->Discard;
rl[1]->Print("label in  1")->RmLabelHeader()->ABCPrint()->arpquerier0;
rl[2]->Print("label in  2")->RmLabelHeader()->ABCPrint()->arpquerier1;

arpquerier0 -> out0;
arpquerier1 -> out1;




