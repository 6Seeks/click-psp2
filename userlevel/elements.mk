# Generated by 'click-buildtool elem2make' on 2019年 12月 08日 星期日 13:28:16 UTC
ELEMENT_OBJS__0 = \
adjusttimestamp.o \
aggcounter.o \
aggpktcounter.o \
aggregatefilter.o \
aggregatefirst.o \
aggregateip.o \
aggregateipaddrpair.o \
aggregateipflows.o \
aggregatelast.o \
aggregatelen.o \
aggregatenotifier.o \
aggregatepaint.o \
anonipaddr.o \
eraseippayload.o \
fromcapdump.o \
fromdagdump.o \
fromipsumdump.o \
fromnetflowsumdump.o \
fromnlanrdump.o \
fromtcpdump.o \
ipsumdump_anno.o \
ipsumdump_icmp.o \
ipsumdump_ip.o \
ipsumdump_link.o \
ipsumdump_payload.o \
ipsumdump_tcp.o \
ipsumdump_udp.o \
ipsumdumpinfo.o \
settimestampdelta.o \
storetimestamp.o \
storeudptimeseqrecord.o \
timefilter.o \
timerange.o \
timesortedsched.o \
timestampaccum.o \
toipflowdumps.o \
toipsumdump.o \

ELEMENT_OBJS__1 = \
ftpportmapper.o \

ELEMENT_OBJS__2 = \
adaptivered.o \
red.o \

ELEMENT_OBJS__3 = \
arpfaker.o \
arpprint.o \
arpquerier.o \
arpresponder.o \
arptable.o \
checkarpheader.o \
ensureether.o \
etherencap.o \
ethermirror.o \
etherpausesource.o \
ethervlanencap.o \
hostetherfilter.o \
ip6ndadvertiser.o \
ip6ndsolicitor.o \
setvlananno.o \
storeetheraddress.o \
stripethervlanheader.o \
vlandecap.o \
vlanencap.o \

ELEMENT_OBJS__4 = \
checkicmpheader.o \
icmperror.o \
icmpipencap.o \
icmppingencap.o \
icmppingresponder.o \
icmppingrewriter.o \
icmprewriter.o \
icmpsendpings.o \

ELEMENT_OBJS__5 = \
checkipheader.o \
checkipheader2.o \
decipttl.o \
directiplookup.o \
fixipsrc.o \
getipaddress.o \
ipaddrpairrewriter.o \
ipaddrrewriter.o \
ipclassifier.o \
ipencap.o \
ipfieldinfo.o \
ipfilter.o \
ipfragmenter.o \
ipgwoptions.o \
ipinputcombo.o \
ipmirror.o \
ipnameinfo.o \
ipoutputcombo.o \
ipprint.o \
ipratemon.o \
ipreassembler.o \
iprewriterbase.o \
iproutetable.o \
iprwmapping.o \
iprwpattern.o \
iprwpatterns.o \
lineariplookup.o \
lookupiproute.o \
lookupiproutelinux.o \
markipce.o \
markipheader.o \
poundradixiplookup.o \
radixiplookup.o \
rangeiplookup.o \
rfc2507c.o \
rfc2507d.o \
ripsend.o \
rripmapper.o \
setipaddress.o \
setipchecksum.o \
setipdscp.o \
setipecn.o \
setrandipaddress.o \
siphmapper.o \
sortediplookup.o \
storeipaddress.o \
stripipheader.o \
truncateippayload.o \
unstripipheader.o \

ELEMENT_OBJS__6 = \
addresstranslator.o \
checkip6header.o \
decip6hlim.o \
getip6address.o \
icmp6error.o \
ip6encap.o \
ip6fragmenter.o \
ip6mirror.o \
ip6print.o \
ip6routetable.o \
lookupip6route.o \
markip6header.o \
protocoltranslator46.o \
protocoltranslator64.o \
setip6address.o \
setip6dscp.o \

ELEMENT_OBJS__7 = \
abcprint.o \
addlabelheader.o \
arpquery.o \
arpresp.o \
checkabcheader.o \
fastpspsource.o \
labelqueue.o \
lookuplabeltable.o \
lookuproute.o \
pqschedqueue.o \
rmlabelheader.o \

ELEMENT_OBJS__8 = \
fixpimsource.o \
igmp.o \
ipmulticasttable.o \
mcastetherencap.o \
pim.o \
pimcontrol.o \
pimforwardingtable.o \

ELEMENT_OBJS__9 = \
fixip6src.o \
icmp6checksum.o \
ip6fixpimsource.o \
ip6mcastetherencap.o \
ip6multicasttable.o \
ip6pim.o \
ip6pimcontrol.o \
ip6pimforwardingtable.o \
mld.o \

ELEMENT_OBJS__10 = \
netflowdata.o \
netflowexport.o \
netflowpacket.o \
netflowprint.o \
netflowtemplate.o \
netflowtemplatecache.o \

ELEMENT_OBJS__11 = \
getssrc.o \

ELEMENT_OBJS__12 = \
simpleidle.o \
simplepriosched.o \
simplepullswitch.o \
simplerrsched.o \

ELEMENT_OBJS__13 = \
align.o \
annotationinfo.o \
averagecounter.o \
bandwidthmeter.o \
bandwidthshaper.o \
block.o \
burster.o \
bwratedsplitter.o \
bwratedunqueue.o \
checkcrc32.o \
checklength.o \
checkpaint.o \
classification.o \
classifier.o \
clickyinfo.o \
compblock.o \
counter.o \
delayshaper.o \
delayunqueue.o \
devirtualizeinfo.o \
discard.o \
discardnofree.o \
drivermanager.o \
dropbroadcasts.o \
drr.o \
flowinfo.o \
frontdropqueue.o \
fullnotequeue.o \
hashswitch.o \
hub.o \
idle.o \
infinitesource.o \
linkunqueue.o \
markmacheader.o \
messageelement.o \
meter.o \
mixedqueue.o \
msqueue.o \
notifierqueue.o \
nullelement.o \
nulls.o \
paint.o \
paintswitch.o \
painttee.o \
print.o \
priosched.o \
pullswitch.o \
quicknotequeue.o \
quitwatcher.o \
randomerror.o \
randomsample.o \
randomsource.o \
randomswitch.o \
ratedsource.o \
ratedsplitter.o \
ratedunqueue.o \
rrsched.o \
rrswitch.o \
script.o \
setannobyte.o \
setcrc32.o \
setpackettype.o \
settimestamp.o \
shaper.o \
simplequeue.o \
staticpullswitch.o \
staticswitch.o \
storedata.o \
stridesched.o \
strideswitch.o \
strip.o \
striptonet.o \
suppressor.o \
switch.o \
tee.o \
threadsafequeue.o \
timedsink.o \
timedsource.o \
timedunqueue.o \
truncate.o \
unqueue.o \
unqueue2.o \
unstrip.o \

ELEMENT_OBJS__14 = \
checktcpheader.o \
checkudpheader.o \
dynudpipencap.o \
iprewriter.o \
settcpchecksum.o \
setudpchecksum.o \
tcpfragmenter.o \
tcpipsend.o \
tcprewriter.o \
udpip6encap.o \
udpipencap.o \
udprewriter.o \

ELEMENT_OBJS__15 = \
bhmtest.o \
biginttest.o \
blockthread.o \
checkpacket.o \
clptest.o \
comparepackets.o \
confparsetest.o \
cryptotest.o \
errortest.o \
functiontest.o \
handlertask.o \
hashtabletest.o \
heaptest.o \
listtest.o \
neighborhoodtest.o \
notifierdebug.o \
nulltask.o \
packettest.o \
queuethreadtest.o \
queueyanktest.o \
randomseed.o \
schedordertest.o \
sorttest.o \
timertest.o \
tokenbuckettest.o \
upstreamnotifier.o \
vectortest.o \

ELEMENT_OBJS__16 = \
balancedthreadsched.o \
spinlockacquire.o \
spinlockinfo.o \
spinlockrelease.o \
staticthreadsched.o \

ELEMENT_OBJS__17 = \
changeuid.o \
chattersocket.o \
controlsocket.o \
fakepcap.o \
fromdevice.o \
fromdump.o \
fromhost.o \
fromrawsocket.o \
fromsocket.o \
handlerproxy.o \
kernelfilter.o \
kerneltap.o \
kerneltun.o \
khandlerproxy.o \
progressbar.o \
rawsocket.o \
socket.o \
todevice.o \
todump.o \
tohost.o \
torawsocket.o \
tosocket.o \
umlswitch.o \

ELEMENT_OBJS = \
$(ELEMENT_OBJS__0) \
$(ELEMENT_OBJS__1) \
$(ELEMENT_OBJS__2) \
$(ELEMENT_OBJS__3) \
$(ELEMENT_OBJS__4) \
$(ELEMENT_OBJS__5) \
$(ELEMENT_OBJS__6) \
$(ELEMENT_OBJS__7) \
$(ELEMENT_OBJS__8) \
$(ELEMENT_OBJS__9) \
$(ELEMENT_OBJS__10) \
$(ELEMENT_OBJS__11) \
$(ELEMENT_OBJS__12) \
$(ELEMENT_OBJS__13) \
$(ELEMENT_OBJS__14) \
$(ELEMENT_OBJS__15) \
$(ELEMENT_OBJS__16) \
$(ELEMENT_OBJS__17) \

$(ELEMENT_OBJS__0): %.o: ../elements/analysis/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__0)): %.s: ../elements/analysis/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__0)): %.ii: ../elements/analysis/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__1): %.o: ../elements/app/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__1)): %.s: ../elements/app/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__1)): %.ii: ../elements/app/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__2): %.o: ../elements/aqm/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__2)): %.s: ../elements/aqm/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__2)): %.ii: ../elements/aqm/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__3): %.o: ../elements/ethernet/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__3)): %.s: ../elements/ethernet/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__3)): %.ii: ../elements/ethernet/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__4): %.o: ../elements/icmp/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__4)): %.s: ../elements/icmp/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__4)): %.ii: ../elements/icmp/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__5): %.o: ../elements/ip/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__5)): %.s: ../elements/ip/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__5)): %.ii: ../elements/ip/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__6): %.o: ../elements/ip6/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__6)): %.s: ../elements/ip6/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__6)): %.ii: ../elements/ip6/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__7): %.o: ../elements/local/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__7)): %.s: ../elements/local/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__7)): %.ii: ../elements/local/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__8): %.o: ../elements/local/multicast/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__8)): %.s: ../elements/local/multicast/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__8)): %.ii: ../elements/local/multicast/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__9): %.o: ../elements/local/multicast6/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__9)): %.s: ../elements/local/multicast6/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__9)): %.ii: ../elements/local/multicast6/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__10): %.o: ../elements/local/netflow/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__10)): %.s: ../elements/local/netflow/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__10)): %.ii: ../elements/local/netflow/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__11): %.o: ../elements/local/unibo_qos/package/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__11)): %.s: ../elements/local/unibo_qos/package/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__11)): %.ii: ../elements/local/unibo_qos/package/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__12): %.o: ../elements/simple/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__12)): %.s: ../elements/simple/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__12)): %.ii: ../elements/simple/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__13): %.o: ../elements/standard/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__13)): %.s: ../elements/standard/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__13)): %.ii: ../elements/standard/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__14): %.o: ../elements/tcpudp/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__14)): %.s: ../elements/tcpudp/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__14)): %.ii: ../elements/tcpudp/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__15): %.o: ../elements/test/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__15)): %.s: ../elements/test/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__15)): %.ii: ../elements/test/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__16): %.o: ../elements/threads/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__16)): %.s: ../elements/threads/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__16)): %.ii: ../elements/threads/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)

$(ELEMENT_OBJS__17): %.o: ../elements/userlevel/%.cc
	$(call cxxcompile,-c $< -o $@,CXX)
$(patsubst %.o,%.s,$(ELEMENT_OBJS__17)): %.s: ../elements/userlevel/%.cc
	$(call cxxcompile_nodep,-S $< -o $@,CXX -S)
$(patsubst %.o,%.ii,$(ELEMENT_OBJS__17)): %.ii: ../elements/userlevel/%.cc
	$(call cxxcompile_nodep,-E $< -o $@,CXXCPP)
