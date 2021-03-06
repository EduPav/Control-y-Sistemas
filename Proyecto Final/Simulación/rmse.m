function rmserr = rmse (estimate, true)
% rmse: rooted mean squarred error between two vectors.
%
% INPUT:
%   estimate: NxM estimate values.
%   true:     NxM true values, reference.
%
% OUTPUT:
%    rmserr: 1xM rooted mean squared error.
%
%   Copyright (C) 2014, Rodrigo Gonzalez, all rights reserved. 
%     
%   This file is part of NaveGo, an open-source MATLAB toolbox for 
%   simulation of integrated navigation systems.
%     
%   NaveGo is free software: you can redistribute it and/or modify
%   it under the terms of the GNU Lesser General Public License (LGPL) 
%   version 3 as published by the Free Software Foundation.
% 
%   This program is distributed in the hope that it will be useful,
%   but WITHOUT ANY WARRANTY; without even the implied warranty of
%   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%   GNU Lesser General Public License for more details.
% 
%   You should have received a copy of the GNU Lesser General Public 
%   License along with this program. If not, see 
%   <http://www.gnu.org/licenses/>.
%
% Version: 004
% Date:    2022/06/11
% Author:  Rodrigo Gonzalez <rodralez@frm.utn.edu.ar>
% URL:     https://github.com/rodralez/navego 

if( any(isnan(estimate)) | any(isnan(true)) )
    error('rmse: input vector with at least one NaN value');
end

if ( size (estimate) ~= size (true) )   
    error('rmse: vectors must have the same length')
end

rmserr =  sqrt ( mean ( ( estimate - true).^2 ) ) ;

end
