class DisponibilidadDocente < ApplicationRecord
  belongs_to :docente
  belongs_to :periodo
  has_one :asignacion
end
