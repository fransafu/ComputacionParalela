class DisponibilidadSala < ApplicationRecord
  belongs_to :sala
  belongs_to :periodo
  has_one :asignacion
  
end
