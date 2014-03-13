/*
    libmaus
    Copyright (C) 2009-2014 German Tischler
    Copyright (C) 2011-2014 Genome Research Limited

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#if ! defined(LIBMAUS_LZ_SNAPPYFILEOUTPUTSTREAM_HPP)
#define LIBMAUS_LZ_SNAPPYFILEOUTPUTSTREAM_HPP

#include <libmaus/lz/SnappyOutputStream.hpp>
#include <libmaus/aio/CheckedOutputStream.hpp>

namespace libmaus
{
	namespace lz
	{
		struct SnappyFileOutputStream
		{
			typedef SnappyFileOutputStream this_type;
			typedef ::libmaus::util::unique_ptr<this_type>::type unique_ptr_type;
			typedef ::libmaus::util::shared_ptr<this_type>::type shared_ptr_type;
		
			// std::ofstream ostr;
			::libmaus::aio::CheckedOutputStream ostr;
			SnappyOutputStream< ::libmaus::aio::CheckedOutputStream > sos;

			SnappyFileOutputStream(std::string const & filename, uint64_t const bufsize = 64*1024)
			: ostr(filename.c_str()), sos(ostr,bufsize) {}
			
			void flush()
			{
				sos.flush();
				ostr.flush();
			}
			
			void put(int const c)
			{
				sos.put(c);
			}
			
			void write(char const * c, uint64_t const n)
			{
				sos.write(c,n);
			}
		};		
	}
}
#endif
