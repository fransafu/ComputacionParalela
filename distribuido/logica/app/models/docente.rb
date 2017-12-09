class Docente < ApplicationRecord
  has_many :disponibilidad_docentes
  belongs_to :departamento
  has_many :cursos
end
