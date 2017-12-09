class Asignacion < ApplicationRecord
  self.table_name = 'asignaciones'
  belongs_to :disponibilidad_sala
  belongs_to :horario
  belongs_to :disponibilidad_docente
end
