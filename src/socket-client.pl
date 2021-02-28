#!/usr/bin/perl -w

# Simple client example which connects to fst-infl2-daemon
# The daemon must have been started already with the command:
#   fst-infl2-daemon 7890 transducer.ca
# This client ist called as follows:
#   perl client.pl localhost 7890
# If the server was started on a different computer, you have
# to replace "localhost" by the server address, e.g. "server.domain.com"

use IO::Socket;
use strict;

my $remote_host = shift || 'localhost';
my $remote_port = shift || 7890;

$| = 1;

# read words to be analysed
while (<>) {
    chomp;
    # open a connection to the server
    my $socket = IO::Socket::INET->new( PeerAddr => $remote_host ,
					PeerPort => $remote_port ,
					Proto => "tcp",
					Type => SOCK_STREAM )
	or die "Couldn't connect to $remote_host : $remote_port : $@\n";

    # send data to the server
    print $socket "$_\n";
    # notify server that request has been sent
    shutdown($socket,1);

    # read results from server
    while (my $result = <$socket>) {
	print $result;
    }
    # close connection
    close($socket);
}
